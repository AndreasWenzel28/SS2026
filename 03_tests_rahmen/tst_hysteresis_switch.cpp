#include <QtTest>
#include <stdexcept>

#include "hysteresis_switch.h"

class TestHysteresisSwitch : public QObject
{
    Q_OBJECT

private slots:
    // Wird einmal vor allen Tests dieser Testklasse aufgerufen.
   /* void initTestCase();

    // Wird vor jedem einzelnen Test aufgerufen.
    void init();

    // Wird nach jedem einzelnen Test aufgerufen.
    void cleanup();

    // Wird einmal nach allen Tests dieser Testklasse aufgerufen.
    void cleanupTestCase();*/

    void startsOff();
    void switchOn();
    void stayOnAt70();
    void switchOff();
    void hysteresisOffStayOff();

};
/*
void TestHysteresisSwitch::initTestCase()
{
    qDebug() << "initTestCase(): wird einmal vor allen Tests ausgefuehrt";
}

void TestHysteresisSwitch::init()
{
    qDebug() << "init(): wird vor jedem Test ausgefuehrt";
}

void TestHysteresisSwitch::cleanup()
{
    qDebug() << "cleanup(): wird nach jedem Test ausgefuehrt";
}

void TestHysteresisSwitch::cleanupTestCase()
{
    qDebug() << "cleanupTestCase(): wird einmal nach allen Tests ausgefuehrt";
}*/

void TestHysteresisSwitch::startsOff()
{
    HysteresisSwitch sw(80.0, 70.0);

    QCOMPARE(sw.isOn(), false);
}

void TestHysteresisSwitch::switchOn()
{
    HysteresisSwitch sw(80.0, 70.0);
    sw.update(80.0);

    QCOMPARE(sw.isOn(), true);
}

void TestHysteresisSwitch::stayOnAt70()
{
    HysteresisSwitch sw(80.0, 70.0);
    sw.update(80.0);
    sw.update(70.0);

    QCOMPARE(sw.isOn(), true);
}

void TestHysteresisSwitch::switchOff()
{
    HysteresisSwitch sw(80.0, 70.0);
    sw.update(80.0);
    sw.update(69.9999);

    QCOMPARE(sw.isOn(), false);
}


void TestHysteresisSwitch::hysteresisOffStayOff()
{
    HysteresisSwitch sw(80.0, 70.0);
    sw.update(75.0);
    QCOMPARE(sw.isOn(), false);
    sw.update(79.99999);
    QCOMPARE(sw.isOn(), false);
    sw.update(70);
    QCOMPARE(sw.isOn(), false);
}

QTEST_MAIN(TestHysteresisSwitch)
#include "tst_hysteresis_switch.moc"
