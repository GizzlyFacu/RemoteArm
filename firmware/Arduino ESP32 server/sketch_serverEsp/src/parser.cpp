#include "parser.h"

Parser::Parser() {}

int Parser::saveParameters(std::string &mensajes)
{
    if (mensajes.length() < 4) {
        std::cout<< "[ERROR][Parser::saveParameter]The message is too short(min: 4 characters)\n";
        return 0;
    }
    std::istringstream stream(mensajes);
    std::string word;
    while (stream >> word) {

        // Es un comando conocido?
        if (command_map.contains(word)) {

            // Si ya queda un comando en construcción, lo guardamos
            if (current.type != Command::ERROR) {
                parsedCommands.push_back(current);
                current = {Command::ERROR, {}};
            }

            current.type = command_map.at(word);
        }
        else {
            // Es parametro
            if (current.type == Command::ERROR) {
                std::cout << "[ERROR][Parser::saveParameter]Parameter without previus command: " << word << "\n";
                return 0;
                //continue;
            }
            current.params.push_back(word);
        }
    }
    // Guardar el ultimo comando si existe
    if (current.type != Command::ERROR) {
        parsedCommands.push_back(current);
    }
    return 1;
}

void Parser::printSavedParameters()
{
    for (const auto& cmd : parsedCommands) {
        std::cout << "Command: ";

        switch (cmd.type) {
        case Command::SET:   std::cout << "SET"; break;
        case Command::GET:   std::cout << "GET"; break;
        case Command::RESET: std::cout << "RESET"; break;
        case Command::PING:  std::cout << "PING"; break;
        default:             std::cout << "ERROR"; break;
        }

        std::cout << "\n";

        for (const auto& param : cmd.params) {
            std::cout << "   Param: " << param << "\n";
        }

        std::cout << "\n";
    }
}
