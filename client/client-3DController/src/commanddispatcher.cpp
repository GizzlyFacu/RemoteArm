#include "commanddispatcher.h"


int CommandDispatcher::sendCommands(const std::vector<ParsedCommand> &parsedCommands)
{
    std::cout<<"[COMMAND DISPATCHER::sendCommands]\n";
    for (const auto& cmd : parsedCommands) {
        std::cout << "Comando: \n";
        switch (cmd.type) {
        case Command::SET:
            std::cout << "SET\n";
            //send 1er and 2nd parameters
            int angleValue;
            angleValue = std::stoi(cmd.params.at(1));
            m_brazoVirtual.set(cmd.params.at(0),angleValue);
            break;
        case Command::GET:
            std::cout << "GET\n";
            //send 1er parametro
            std::cout<<"Getting Parameter: ["<<cmd.params.at(0)<<"]="<<m_brazoVirtual.get(cmd.params.at(0))<<"\n";
            break;
        case Command::RESET:
            std::cout << "RESET\n";
            //reset command
            break;
        case Command::PING:
            std::cout << "PING\n";
            //ping command
            break;
        default:
            std::cout << "ERROR";
            break;
        }

        std::cout << "\n";
    }
    return 0;
}
