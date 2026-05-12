#ifndef HYSTERESIS_SWITCH_H
#define HYSTERESIS_SWITCH_H

class HysteresisSwitch
{
public:
    HysteresisSwitch(double onThreshold, double offThreshold);

    bool update(double value);
    bool isOn() const;

private:
    double m_onThreshold;
    double m_offThreshold;
    bool m_isOn = false;
};

#endif // HYSTERESIS_SWITCH_H
