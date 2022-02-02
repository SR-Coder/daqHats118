#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <unistd.h>
#include <QThread>
#include <QVariant>
#include "daqhat118.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    QThread* thread = new QThread();
    DaqHat118* task = new DaqHat118();

    task->moveToThread(thread);

    connect(thread, SIGNAL(started()), task, SLOT(getData()));
//    connect(task, SIGNAL(daqHatSigChange(double)), this, SLOT(displayData(double)));
    connect(task, SIGNAL(dhsc(QList<double>)), this, SLOT(displayData2(QList<double>)));

    thread->start();

}

MainWindow::~MainWindow()
{
    delete ui;
    thread()->exit();
}

void MainWindow::displayData(double raw_data)
{
    ui->voltage1->display(raw_data);
}

void MainWindow::displayData2(QList<double> data)
{

    ui->voltage1->display(data[0]);
    ui->voltage2->display(data[1]);
    ui->voltage3->display(data[2]);
    ui->voltage4->display(data[3]);
    ui->voltage5->display(data[4]);
    ui->voltage6->display(data[5]);
    ui->voltage7->display(data[6]);
    ui->voltage8->display(data[7]);
}


