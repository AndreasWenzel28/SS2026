# Test-Rahmen für die Live-Vorführung

Dieses Verzeichnis enthält einen minimalen Qt-Test-Rahmen.

Zusätzlich sind die Qt-Test-Hilfsfunktionen enthalten:

```cpp
void initTestCase();
void init();
void cleanup();
void cleanupTestCase();
```

Sie geben jeweils per `qDebug()` aus, wann sie aufgerufen werden.

## Aufrufreihenfolge

```text
initTestCase()

  init()
  startsOff()
  cleanup()

  init()
  atOnThresholdSwitchesOn()
  cleanup()

cleanupTestCase()
```

Für unser kleines Beispiel brauchen wir diese Funktionen eigentlich nicht. Jeder Test erzeugt sein eigenes Testobjekt und bleibt dadurch unabhängig.
