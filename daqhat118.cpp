#include "daqhat118.h"
#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include "mainwindow.h"
#include <QTimer>

QTimer* timer = new QTimer;

DaqHat118::DaqHat118()
{

}
DaqHat118::~DaqHat118()
{

}


void DaqHat118::getData()
{
    double v0, v1, v2, v3, v4, v5, v6, v7;
    mcc118_open(address);

    while(1)
    {
        // get the data from the daqhat sheild
        mcc118_a_in_read(address, 0, 0x0000, &v0);
        mcc118_a_in_read(address, 1, 0x0000, &v1);
        mcc118_a_in_read(address, 2, 0x0000, &v2);
        mcc118_a_in_read(address, 3, 0x0000, &v3);
        mcc118_a_in_read(address, 4, 0x0000, &v4);
        mcc118_a_in_read(address, 5, 0x0000, &v5);
        mcc118_a_in_read(address, 6, 0x0000, &v6);
        mcc118_a_in_read(address, 7, 0x0000, &v7);

        // add the data to the qlist
        voltArr = {v0, v1, v2, v3, v4, v5, v6, v7};

        // emit the signal when the data is updated
        emit dhsc(voltArr);



    }
}


