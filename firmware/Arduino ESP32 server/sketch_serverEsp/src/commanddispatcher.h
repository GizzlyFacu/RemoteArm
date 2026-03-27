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
        std::cout<<"Replaceable 'Modify Action' for BrazoVirtual.h\n";
    }
};

class CommandDispatcher
{
public:
    CommandDispatcher()=default;

    void setBrazo(BrazoVirtual* brazoVirtual){
        m_brazoVirtual=brazoVirtual;
    }
    int sendCommands(const std::vector<ParsedCommand> &parsedCommands);

private:
    BrazoVirtual* m_brazoVirtual=nullptr;
    SetCommand setBrazoAngulo;

};

#endif // COMMANDDISPATCHER_H
