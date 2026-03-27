#include "brazovirtual.h"


void BrazoVirtual::set(std::string bone, int Angle)
{
    std::cout<<"[BrazoVirtual::set]"<<bone<<" Setted Up at: "<<Angle<<"\n";
    if (bone=="L") {
        m_lowBone=Angle;
    }
    else if (bone=="M") {
        m_midBone = Angle;
    }
    else if(bone=="H"){
        m_highBone = Angle;
    }
    notifChanges();
}

int BrazoVirtual::get(std::string bone)
{
    if (bone=="L") {
        return m_lowBone;
    }
    else if (bone=="M") {
        return m_midBone;
    }
    else if(bone=="H"){
        return m_highBone;
    }
    return -1;
}

void BrazoVirtual::subscribe(std::function<void ()> &Subscriber)
{
    std::cout<<"[BrazoVirtual::subscribe]Something was subscribed\n";
    subscribers.push_back(Subscriber);
}

void BrazoVirtual::notifChanges()
{
    //1.funcion notificar
    for (auto &x : subscribers) {
        std::cout<<"[BrazoVirtual::notifChanges]Notifying subcribers...\n";
        x();
    }
}
