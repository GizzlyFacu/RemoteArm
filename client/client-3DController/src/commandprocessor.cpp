#include "commandprocessor.h"
CommandProcessor::CommandProcessor(std::string& Message, BrazoVirtual& BrazoVirt)
    :  m_brazoVirtual(BrazoVirt), m_cmdDispatcher(BrazoVirt)
{
    if (m_parser.saveParameters(Message)) {
        m_parser.printSavedParameters();
        if (m_parserValider.validate(m_parser.parsedCommands)) {
            m_cmdDispatcher.sendCommands(m_parser.parsedCommands);
        }
    }

}
