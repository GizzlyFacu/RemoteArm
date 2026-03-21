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
    CommandProcessor(std::string& Message);

private:
    BrazoVirtual& m_brazoVirtual;
    Parser m_parser;
    ParserValidate m_parserValider;
    CommandDispatcher m_cmdDispatcher;
};

#endif // COMMANDPROCESSOR_H
