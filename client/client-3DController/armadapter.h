#ifndef ARMADAPTER_H
#define ARMADAPTER_H

#include <QObject>
#include <iostream>
#include <QQuaternion>
#include <QVector3D>
class ArmAdapter : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QQuaternion angleLowBone READ angleLowBone WRITE setAngleLowBone NOTIFY angleLowBoneChanged FINAL)
    Q_PROPERTY(QQuaternion angleMidBone READ angleMidBone NOTIFY angleMidBoneChanged FINAL)
    Q_PROPERTY(QQuaternion angleHighBone READ angleHighBone NOTIFY angleHighBoneChanged FINAL)
public:
    explicit ArmAdapter(QObject *parent = nullptr);

    QQuaternion angleLowBone() const;
    void setAngleLowBone(const QQuaternion &newAngleLowBone);
    void setAngleLowBoneFromINT(int AngleLowBone);
    float getAngleLowBone();

    QQuaternion angleMidBone() const;
    void setAngleMidBoneFromINT(int AngleMidBone);
    float getAngleMidBone();


    QQuaternion angleHighBone() const;
    void setAngleHighBoneFromINT(int AngleHighBone);
    float getAngleHighBone();

public slots:

signals:
    void angleLowBoneChanged();
    void angleMidBoneChanged();
    void angleHighBoneChanged();

private:
    QQuaternion m_angleLowBone;
    QQuaternion m_angleMidBone;
    QQuaternion m_angleHighBone;
};

#endif // ARMADAPTER_H
