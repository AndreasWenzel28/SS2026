#include "hysteresis_switch.h"

#include <stdexcept>

HysteresisSwitch::HysteresisSwitch(double onThreshold, double offThreshold)
    : m_onThreshold(onThreshold),
      m_offThreshold(offThreshold)
{
    if (offThreshold >= onThreshold) {
        throw std::invalid_argument("offThreshold must be smaller than onThreshold");
    }
}

bool HysteresisSwitch::update(double value)
{
    bool m_isOnOld=m_isOn;
    if (!m_isOn && value >= m_onThreshold) {
        m_isOn = true;
    } else if (m_isOn && value < m_offThreshold) {
        m_isOn = false;
    }

    if(m_isOn!=m_isOnOld)
    {
        emit(signalSwitched(m_isOn));
    }

    return m_isOn;
}

bool HysteresisSwitch::isOn() const
{
    return m_isOn;
}
