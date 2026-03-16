#ifndef PARSERVALIDATE_H
#define PARSERVALIDATE_H
#include <vector>
#include "parser.h"
#include <unordered_map>
enum class ParameterKind{
    //arm_joint
    INVALID,
    LOW,
    MID,
    HIGH

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
        {"INVALID",ParameterKind::LOW},
        {"LOW",ParameterKind::LOW},
        {"MID",ParameterKind::MID},
        {"HIGH",ParameterKind::HIGH}
    };
    std::unordered_map<std::string,Range> param_ranges_hash{
        {"LOW",Range{0,180}},
        {"MID",Range{0,90}},
        {"HIGH",Range{0,90}}
    };
    int validate(const std::vector<ParsedCommand> &parsedCommands);

};

#endif // PARSERVALIDATE_H
