#ifndef COMMANDDISPATCHER_H
#define COMMANDDISPATCHER_H
#include "parser.h"
#include "brazovirtual.h"

class ICommand{
public:
    virtual ~ICommand()=default;
    virtual void configurate()=0;
};

class SetCommand:public ICommand{
    void configurate()override{
        std::cout<<"Accion de modificar brazovirtual.h\n";
    }
};

class CommandDispatcher
{
public:
    CommandDispatcher(BrazoVirtual& brazoVirtual)
        :  m_brazoVirtual(brazoVirtual){}

    int sendCommands(const std::vector<ParsedCommand> &parsedCommands);
private:
    BrazoVirtual& m_brazoVirtual;
    SetCommand setBrazoAngulo;

};

#endif // COMMANDDISPATCHER_H
