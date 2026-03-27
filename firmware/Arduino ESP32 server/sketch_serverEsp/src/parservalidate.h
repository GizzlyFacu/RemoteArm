#ifndef PARSERVALIDATE_H
#define PARSERVALIDATE_H
#include <vector>
#include "parser.h"
#include <unordered_map>
enum class ParameterKind{
    //arm_joint
    INVALID,
    L,
    M,
    H

    //en otro caso colocar aca
    //POSE1,
    //POSE2,
    //POSE3,
    //POSE4,
};

struct Range{
    int min;
    int max;
    constexpr bool contains(int value) const noexcept {
        return value >= min && value <= max;
    }
};

struct CommandRule{
    Command type;
    size_t min_par;
    size_t max_par;
};

class ParserValidate
{
public:
    ParserValidate();
    std::unordered_map<std::string,ParameterKind> parameters_hash{
        {"INVALID",ParameterKind::L},
        {"L",ParameterKind::L},
        {"M",ParameterKind::M},
        {"H",ParameterKind::H}
    };
    std::unordered_map<std::string,Range> param_ranges_hash{
        {"L",Range{0,180}},
        {"M",Range{0,90}},
        {"H",Range{0,90}}
    };
    int validate(const std::vector<ParsedCommand> &parsedCommands);

};

#endif // PARSERVALIDATE_H
