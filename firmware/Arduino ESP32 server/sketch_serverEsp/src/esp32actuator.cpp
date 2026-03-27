#include "esp32actuator.h"
#include <Arduino.h>
#include <iostream>
void Esp32Actuator::setAngleLowBone(int newAngleLowBone)
{
    if (m_angleLowBone == newAngleLowBone)
        return;
    m_angleLowBone = newAngleLowBone;
}

void Esp32Actuator::setAngleMidBone(int newAngleMidBone)
{
    if (m_angleMidBone == newAngleMidBone)
        return;
    m_angleMidBone = newAngleMidBone;
}

void Esp32Actuator::setAngleHighBone(int newAngleHighBone)
{
    if (m_angleHighBone == newAngleHighBone)
        return;
    m_angleHighBone = newAngleHighBone;

    Serial.print("[ESP32ACTUATOR::setAngle]HighBone Changed: Angle[");
    Serial.println(m_angleHighBone);
    //std::cout<<"[ESP32ACTUATOR::setAngle]HighBone Changed: Angle["<<m_angleHighBone<<"]\n";
}
