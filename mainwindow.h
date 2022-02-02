#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "./daqhat118.h"



namespace Ui {


class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    void myFunc();
    int count = 0;




public slots:
    void displayData(double raw_data);
    void displayData2(QList<double> data);


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
