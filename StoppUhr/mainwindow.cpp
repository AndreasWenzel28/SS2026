#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , myTimer(this)
{
    ui->setupUi(this);
    MakeConnections();
    myTimer.setInterval(10);
    myTimer.setSingleShot(false);
   // myTimer.start();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::MakeConnections(void)
{
    connect(ui->pushButtonStartStop,SIGNAL(clicked(bool)),this,SLOT(slotButtonStartStop()));
    connect(ui->pushButtonReset,SIGNAL(clicked(bool)),this,SLOT(slotButtonReset()));
    connect(&myTimer,SIGNAL(timeout()),this,SLOT(slotRefresh()));

}


void MainWindow::slotButtonStartStop(void)
{

    //Ist es Start oder Stop
    if(ui->pushButtonStartStop->text()=="Start")
    {
        qDebug()<< "Start-clicked";
        myTimer.start();
        lastStartTime=QTime::currentTime();
        ui->pushButtonStartStop->setText("Stop");
    }
    else
    {
        qDebug()<< "Stop-clicked";
        myTimer.stop();
        slotRefresh();
        ui->pushButtonStartStop->setText("Start");
    }
}

void MainWindow::slotButtonReset(void)
{
    qDebug()<< "Reset-clicked";
}

void MainWindow::slotRefresh(void)
{
    int hours, minutes,seconds;
    QTime now=QTime::currentTime();
    int ms=lastStartTime.msecsTo(now);

    qDebug()<<"Ms="<<ms;

    ui->lcdNumberHundertstel->display((ms%1000)/10);
    ms=ms/1000;
    ui->lcdNumberSek->display(ms%60);
    ms=ms/60;
    ui->lcdNumberMin->display(ms%60);
    ms=ms/60;
}



