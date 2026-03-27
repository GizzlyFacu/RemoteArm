#ifndef COMMANDPROCESSOR_H
#define COMMANDPROCESSOR_H
#include <string>
#include "parser.h"
#include "parservalidate.h"
#include "brazovirtual.h"
#include "commanddispatcher.h"
class CommandProcessor
{
public:
    CommandProcessor()=default;
    void setBrazo(BrazoVirtual& BrazoVirt);
    void sendMessage(std::string Message);
private:
    Parser m_parser;
    ParserValidate m_parserValider;
    CommandDispatcher m_cmdDispatcher;
};

#endif // COMMANDPROCESSOR_H
