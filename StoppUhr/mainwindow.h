#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QTime>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //Konstruktor
    MainWindow(QWidget *parent = nullptr);
    //Destructor
    ~MainWindow();

protected slots:
    void slotButtonStartStop(void);
    void slotButtonReset(void);
    void slotRefresh(void);


private:
    void MakeConnections(void);
    Ui::MainWindow *ui;

    QTimer myTimer;
    QTime lastStartTime;
};
#endif // MAINWINDOW_H
