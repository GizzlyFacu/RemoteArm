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

    void set(std::string bone, int Angle);
    int get(std::string bone);

    //interfaces
    void subscribe(std::function<void()> &Subscriber);
    void notifChanges();
private:
    int m_lowBone{};
    int m_midBone{};
    int m_highBone{};
    std::vector<std::function<void()>> subscribers;
};

#endif // BRAZOVIRTUAL_H
