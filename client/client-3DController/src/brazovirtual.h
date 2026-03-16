#ifndef BRAZOVIRTUAL_H
#define BRAZOVIRTUAL_H
#include <string>
#include <iostream>
#include <vector>
#include <functional>

class BrazoVirtual
{
public:
    BrazoVirtual()=default;

    void set(std::string bone, int Angle){
        std::cout<<"[BrazoVirtual::set]"<<bone<<" Setted Up at: "<<Angle<<"\n";
        if (bone=="LOW") {
            m_lowBone=Angle;
        }
        else if (bone=="MID") {
            m_midBone = Angle;
        }
        else if(bone=="HIGH"){
            m_highBone = Angle;
        }
        notifChanges();
    }
    int get(std::string bone){
        if (bone=="LOW") {
            return m_lowBone;
        }
        else if (bone=="MID") {
            return m_midBone;
        }
        else if(bone=="HIGH"){
            return m_highBone;
        }
        return -1;
    }

    //interfaces
    void subscribe(std::function<void()> &Subscriber){
        std::cout<<"[BrazoVirtual::subscribe]Se ha suscrito algo\n";
        subscribers.push_back(Subscriber);
    }
    void notifChanges(){
        //1.funcion notificar
        for (auto &x : subscribers) {
            std::cout<<"[BrazoVirtual::notifChanges]Notificando a los subscribers...\n";
            x();
        }
    }
private:
    int m_lowBone{};
    int m_midBone{};
    int m_highBone{};
    std::vector<std::function<void()>> subscribers;
};

#endif // BRAZOVIRTUAL_H
