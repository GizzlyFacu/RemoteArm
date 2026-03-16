#include "armadapter.h"

ArmAdapter::ArmAdapter(QObject *parent)
    : QObject{parent}
{

}


QQuaternion ArmAdapter::angleLowBone() const
{
    return m_angleLowBone;
}

void ArmAdapter::setAngleLowBone(const QQuaternion &newAngleLowBone)
{
    if (m_angleLowBone == newAngleLowBone)
        return;
    m_angleLowBone = newAngleLowBone;
    emit angleLowBoneChanged();
}

void ArmAdapter::setAngleLowBoneFromINT(int AngleLowBone)
{
    //int to quaternion desde el eje Equis

    QQuaternion newAngleLowBone = QQuaternion::fromAxisAndAngle(0.0f,0.0f,-1.0f,(float)AngleLowBone);
    if (m_angleLowBone == newAngleLowBone)
        return;
    m_angleLowBone = newAngleLowBone;
    std::cout<<"[ArmAdapter::setAngle]LowBone Changed: Angle["<<AngleLowBone<<"]\n";
    emit angleLowBoneChanged();
}

float ArmAdapter::getAngleLowBone()
{
    float angle;
    QVector3D axis;
    m_angleLowBone.getAxisAndAngle(&axis, &angle);
    return angle;
}

QQuaternion ArmAdapter::angleMidBone() const
{
    return m_angleMidBone;
}

void ArmAdapter::setAngleMidBoneFromINT(int AngleMidBone)
{
    //int to quaternion desde el eje Equis
    QQuaternion newAngleMidBone = QQuaternion::fromAxisAndAngle(0.0f,0.0f,-1.0f,(float)AngleMidBone);
    if (m_angleMidBone == newAngleMidBone)
        return;
    m_angleMidBone = newAngleMidBone;
    std::cout<<"[ArmAdapter::setAngle]MidBone Changed: Angle["<<AngleMidBone<<"]\n";
    emit angleMidBoneChanged();
}

float ArmAdapter::getAngleMidBone()
{
    float angle;
    QVector3D axis;
    m_angleMidBone.getAxisAndAngle(&axis, &angle);
    return angle;
}

QQuaternion ArmAdapter::angleHighBone() const
{
    return m_angleHighBone;
}

void ArmAdapter::setAngleHighBoneFromINT(int AngleHighBone)
{
    //int to quaternion desde el eje Equis
    QQuaternion newAngleHighBone = QQuaternion::fromAxisAndAngle(0.0f,0.0f,-1.0f,(float)AngleHighBone);
    if (m_angleHighBone == newAngleHighBone)
        return;
    m_angleHighBone = newAngleHighBone;
    std::cout<<"[ArmAdapter::setAngle]HighBone Changed: Angle["<<AngleHighBone<<"]\n";
    emit angleHighBoneChanged();
}

float ArmAdapter::getAngleHighBone()
{
    float angle;
    QVector3D axis;
    m_angleHighBone.getAxisAndAngle(&axis, &angle);
    return angle;
}
