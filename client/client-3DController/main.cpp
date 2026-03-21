#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <functional>
#include "commandprocessorqt.h"
#include "armadapter.h"
#include "brazovirtual.h"
int main(int argc, char *argv[])
{

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    std::string mensajesEjemplo =
        "GET LOW "
        "SET MID 20 "
        "SET HIGH 50 "
        "PING "
        "RESET ";

    BrazoVirtual brazo;
    ArmAdapter virtualArmQT;
    qmlRegisterSingletonInstance<ArmAdapter>("com.giz.virtualArmQT", 1, 0, "VirtualArmQT", &virtualArmQT);
    //conectando cada hueso de brazo con virtualArmQT
    std::function<void()> subscriberLowBone=[&brazo,&virtualArmQT](){
        virtualArmQT.setAngleLowBoneFromINT(brazo.get("LOW"));
    };
    std::function<void()> subscriberMidBone=[&brazo,&virtualArmQT](){
        virtualArmQT.setAngleMidBoneFromINT(brazo.get("MID"));
    };
    std::function<void()> subscriberHighBone=[&brazo,&virtualArmQT](){
        virtualArmQT.setAngleHighBoneFromINT(brazo.get("HIGH"));
    };

    brazo.subscribe(subscriberLowBone);
    brazo.subscribe(subscriberMidBone);
    brazo.subscribe(subscriberHighBone);

    CommandProcessorQT cmd(&app);
    cmd.setBrazo(brazo);
    qmlRegisterSingletonInstance<CommandProcessorQT>("com.giz.cmdVirtualArmQT", 1, 0, "CmdVirtualArmQT", &cmd);

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("RobotArmPrueba", "Main");

    return app.exec();
}
