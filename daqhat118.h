#ifndef DAQHAT118_H
#define DAQHAT118_H
#include <QObject>
#include <daqhats.h>
#include <QList>




class DaqHat118 : public QObject
{
    Q_OBJECT
public:
    DaqHat118();
    ~DaqHat118();

    uint8_t address = 0;
    uint8_t channel = 0;

    uint32_t options = OPTS_DEFAULT;

    int result = RESULT_SUCCESS;
    int sample_interval = 500;

    double value;
    double volt2;

    QList<double> voltArr;

    QTimer* timer;


public slots:
    void getData();
    void timerData();

signals:
    void daqHatSigChange(double data);
    void dhsc(QList<double> data);


};

#endif // DAQHAT118_H
