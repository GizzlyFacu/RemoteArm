#ifndef PARSER_H
#define PARSER_H
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>


enum class Command {
    SET,
    GET,
    RESET,
    PING,
    ERROR
};
struct ParsedCommand {
    Command type;
    std::vector<std::string> params;
};


class Parser
{
public:
    Parser();
    std::unordered_map<std::string, Command> command_map {
        {"SET", Command::SET},
        {"GET", Command::GET},
        {"RESET", Command::RESET},
        {"PING", Command::PING}
    };
    int saveParameters(std::string &mensaje);
    void printSavedParameters();
    std::vector<ParsedCommand> parsedCommands;

private:
    ParsedCommand current{Command::ERROR,{}};
};

#endif // PARSER_H
