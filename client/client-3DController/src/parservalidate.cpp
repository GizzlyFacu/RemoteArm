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
        std::cout << "Comando: \n";
        //validador cantidad parametros
        switch (cmd.type) {
        case Command::SET:
            std::cout << "SET\n";
            //verificacion tamanio total de parametros
            if(!(cmd.params.size()==setRule.max_par)){

                std::cout<<"[ERROR][ParserValidate::validate]\nSET no cumple con la cantidad de parametros establecidos\n";
                std::cout<<"Parametros establecido: "<<setRule.max_par<<" Parametros ingresados: "<<cmd.params.size()<<"\n";
                return 0;
            }
            //verificacion 1er parametro
            if(parameters_hash.contains(cmd.params.at(0))){
                std::cout<<"Parametro 1 Valido:["<<cmd.params.at(0)<<"]\n";
                //wey esto es el QString::toint()
                int angleValue;
                try {
                    angleValue = std::stoi(cmd.params.at(1));
                } catch (const std::exception&) {
                    // Error de parseo
                    std::cout<<"[ERROR][ParserValidate::validate]\nParametro 2 Invalido:["<<cmd.params.at(1)<<"]\n";
                    std::cout<<"El segundo parametro en SET debe de ser numeros enteros brr brr patapim\n";
                    return 0;
                }
                //verificacion 2do parametro
                if(param_ranges_hash.at(cmd.params.at(0)).contains(angleValue)){
                    std::cout<<"Parametro 2 Valido: esta dentro del rango\n- valor: ["<<angleValue<<"]\n";
                }
                else {
                    std::cout<<"[ERROR][ParserValidate::validate]\nParametro 2 Invalido: No esta dentro del rango de parametros aceptados para [" << cmd.params.at(0)<<"]\n";
                    std::cout<<"- valor min: ["<<param_ranges_hash.at(cmd.params.at(0)).min<<"]\n";
                    std::cout<<"- valor max: ["<<param_ranges_hash.at(cmd.params.at(0)).max<<"]\n";
                    std::cout<<"- valor ingresado: ["<<angleValue<<"]\n";
                    return 0;
                }

            }
            else {
                std::cout<<"[ERROR][ParserValidate::validate]\nEl primer parametro no pertenece a SET:["<<cmd.params.at(0)<<"]\n";
                return 0;
            }
            break;
        case Command::GET:
            std::cout << "GET\n";
            if(!(cmd.params.size()==getRule.max_par)){
                std::cout<<"[ERROR][ParserValidate::validate]\nGET no cumple con la cantidad de parametros establecidos\n";
                std::cout<<"Parametros establecido: "<<getRule.max_par<<" Parametros ingresados: "<<cmd.params.size()<<"\n";
                return 0;
            }
            //verificacion 1er parametro
            if(parameters_hash.contains(cmd.params.at(0))){
                std::cout<<"Parametro 1 Valido:["<<cmd.params.at(0)<<"]\n";
            }
            else {
                std::cout<<"[ERROR][ParserValidate::validate]\nEl primer parametro no pertenece a GET:["<<cmd.params.at(0)<<"]\n";
                return 0;
            }
            break;
        case Command::RESET:
            std::cout << "RESET\n";
            if(!(cmd.params.size()==resetRule.max_par)){
                std::cout<<"[ERROR][ParserValidate::validate]\nRESET no cumple con la cantidad de parametros establecidos\n";
                std::cout<<"Parametros establecido: "<<resetRule.max_par<<" Parametros ingresados: "<<cmd.params.size()<<"\n";
                return 0;
            }
            break;
        case Command::PING:
            std::cout << "PING\n";
            if(!(cmd.params.size()==pingRule.max_par)){
                std::cout<<"[ERROR][ParserValidate::validate]\nPING no cumple con la cantidad de parametros establecidos\n";
                std::cout<<"Parametros establecido: "<<pingRule.max_par<<" Parametros ingresados: "<<cmd.params.size()<<"\n";
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
