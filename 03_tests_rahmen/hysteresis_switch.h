#ifndef HYSTERESIS_SWITCH_H
#define HYSTERESIS_SWITCH_H

#include <QObject>

class HysteresisSwitch:public QObject
{
    Q_OBJECT
public:
    HysteresisSwitch(double onThreshold, double offThreshold);

    bool update(double value);
    bool isOn() const;

signals:
    void signalSwitched(bool);

private:
    double m_onThreshold;
    double m_offThreshold;
    bool m_isOn = false;
};

#endif // HYSTERESIS_SWITCH_H
