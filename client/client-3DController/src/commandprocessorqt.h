#ifndef COMMANDPROCESSORQT_H
#define COMMANDPROCESSORQT_H

#include <QObject>
#include <QString>
#include <QDebug>
#include <string>
#include "parser.h"
#include "parservalidate.h"
#include "brazovirtual.h"
#include "commanddispatcher.h"
class CommandProcessorQT : public QObject
{
    Q_OBJECT

public:
    explicit CommandProcessorQT(QObject *parent = nullptr);
public slots:
    void setBrazo(BrazoVirtual& BrazoVirt){
        m_cmdDispatcher.setBrazo(&BrazoVirt);
    }

    void sendMessage(QString Message){
        std::string message = Message.toStdString();
        if (m_parser.saveParameters(message)) {
            m_parser.printSavedParameters();
            if (m_parserValider.validate(m_parser.parsedCommands)) {
                if(m_cmdDispatcher.sendCommands(m_parser.parsedCommands)){
                    std::cout<<"[[CMD]] mensaje enviado con exito";
                }
            }
        }
    }
signals:
private:
    Parser m_parser;
    ParserValidate m_parserValider;
    CommandDispatcher m_cmdDispatcher;
};

#endif // COMMANDPROCESSORQT_H
