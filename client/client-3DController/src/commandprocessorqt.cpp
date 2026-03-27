#include "commandprocessorqt.h"

CommandProcessorQT::CommandProcessorQT(QObject *parent)
    : QObject{parent}
{}

void CommandProcessorQT::setBrazo(BrazoVirtual &BrazoVirt)
{
    m_cmdDispatcher.setBrazo(&BrazoVirt);
}

void CommandProcessorQT::sendMessage(QString Message)
{
    std::string message = Message.toStdString();
    if (m_parser.saveParameters(message)) {
        m_parser.printSavedParameters();
        if (m_parserValider.validate(m_parser.parsedCommands)) {
            if(m_cmdDispatcher.sendCommands(m_parser.parsedCommands)){
                std::cout<<"[[CMD]] Message Successfully Sent!";
            }
        }
    }
}
