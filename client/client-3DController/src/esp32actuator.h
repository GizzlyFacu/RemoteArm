#ifndef ESP32ACTUATOR_H
#define ESP32ACTUATOR_H

class Esp32Actuator
{
public:
    Esp32Actuator()=default;
    void setAngleLowBone(int newAngleLowBone);
    int getAngleLowBone();

    void setAngleMidBone(int newAngleMidBone);
    int getAngleMidBone();

    void setAngleHighBone(int newAngleHighBone);
    int getAngleHighBone();

private:
    int m_angleLowBone;
    int m_angleMidBone;
    int m_angleHighBone;
};

#endif // ESP32ACTUATOR_H
