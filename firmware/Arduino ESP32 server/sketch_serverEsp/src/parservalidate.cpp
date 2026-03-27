#include "parservalidate.h"


ParserValidate::ParserValidate() {}

int ParserValidate::validate(const std::vector<ParsedCommand> &parsedCommands){
    std::cout<<"[ParserValidate::validate]\n";
    CommandRule setRule{Command::SET,2,2};
    CommandRule getRule{Command::GET,1,1};
    CommandRule resetRule{Command::RESET,0,0};
    CommandRule pingRule{Command::PING,0,0};
    //validador semental
    for (const auto& cmd : parsedCommands) {
        std::cout << "Command: \n";
        //validador cantidad parametros
        switch (cmd.type) {
        case Command::SET:
            std::cout << "SET\n";
            //verificacion tamanio total de parametros
            if(!(cmd.params.size()==setRule.max_par)){

                std::cout<<"[ERROR][ParserValidate::validate]\nSET  doesn't meet the established number of parameters \n";
                std::cout<<"Established Parameters: "<<setRule.max_par<<" Parameters entered: "<<cmd.params.size()<<"\n";
                return 0;
            }
            //verificacion 1er parametro
            if(parameters_hash.contains(cmd.params.at(0))){
                std::cout<<"Parameter 1 Valid:["<<cmd.params.at(0)<<"]\n";
                //wey esto es el QString::toint()
                int angleValue;
                try {
                    angleValue = std::stoi(cmd.params.at(1));
                } catch (const std::exception&) {
                    // Error de parseo
                    std::cout<<"[ERROR][ParserValidate::validate]\nParameter 2 Invalid:["<<cmd.params.at(1)<<"]\n";
                    std::cout<<"Second Parameter must be an INT\n";
                    return 0;
                }
                //verificacion 2do parametro
                if(param_ranges_hash.at(cmd.params.at(0)).contains(angleValue)){
                    std::cout<<"Parameter 2 Valid: is in range\n- value: ["<<angleValue<<"]\n";
                }
                else {
                    std::cout<<"[ERROR][ParserValidate::validate]\nParameter 2 Invalid: isn't in the parameter range for [" << cmd.params.at(0)<<"]\n";
                    std::cout<<"- min value: ["<<param_ranges_hash.at(cmd.params.at(0)).min<<"]\n";
                    std::cout<<"- max value: ["<<param_ranges_hash.at(cmd.params.at(0)).max<<"]\n";
                    std::cout<<"- entered value: ["<<angleValue<<"]\n";
                    return 0;
                }

            }
            else {
                std::cout<<"[ERROR][ParserValidate::validate]\nThe first parameter doesn't belong to SET:["<<cmd.params.at(0)<<"]\n";
                return 0;
            }
            break;
        case Command::GET:
            std::cout << "GET\n";
            if(!(cmd.params.size()==getRule.max_par)){
                std::cout<<"[ERROR][ParserValidate::validate]\nGET  doesn't meet the established number of parameters \n";
                std::cout<<"Established Parameters: "<<getRule.max_par<<" Parameters entered: "<<cmd.params.size()<<"\n";
                return 0;
            }
            //verificacion 1er parametro
            if(parameters_hash.contains(cmd.params.at(0))){
                std::cout<<"Parameter 1 Valid:["<<cmd.params.at(0)<<"]\n";
            }
            else {
                std::cout<<"[ERROR][ParserValidate::validate]\nThe first parameter doesn't belong to GET:["<<cmd.params.at(0)<<"]\n";
                return 0;
            }
            break;
        case Command::RESET:
            std::cout << "RESET\n";
            if(!(cmd.params.size()==resetRule.max_par)){
                std::cout<<"[ERROR][ParserValidate::validate]\nRESET doesn't meet the established number of parameters \n";
                std::cout<<"Established Parameters: "<<resetRule.max_par<<" Parameters entered: "<<cmd.params.size()<<"\n";
                return 0;
            }
            break;
        case Command::PING:
            std::cout << "PING\n";
            if(!(cmd.params.size()==pingRule.max_par)){
                std::cout<<"[ERROR][ParserValidate::validate]\nPING doesn't meet the established number of parameters \n";
                std::cout<<"Established Parameters: "<<pingRule.max_par<<" Parameters entered: "<<cmd.params.size()<<"\n";
                return 0;
            }
            break;
        default:
            std::cout << "ERROR ndea sepa dios que paso/n";
            break;
        }

        std::cout << "\n";
    }
    return 1;
}
