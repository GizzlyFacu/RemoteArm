#include "commandprocessor.h"

void CommandProcessor::setBrazo(BrazoVirtual &BrazoVirt)
{
    m_cmdDispatcher.setBrazo(&BrazoVirt);
}

void CommandProcessor::sendMessage(std::string Message)
{
    std::string message = Message;
    if (m_parser.saveParameters(message)) {
        m_parser.printSavedParameters();
        if (m_parserValider.validate(m_parser.parsedCommands)) {
            if(m_cmdDispatcher.sendCommands(m_parser.parsedCommands)){
                std::cout<<"[[CMD]] mensaje enviado con exito";
            }
        }
    }
}
