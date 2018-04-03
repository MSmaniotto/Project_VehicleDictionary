#ifndef COUNTDOWNTIMER_H
#define COUNTDOWNTIMER_H

#include <QWidget>
#include <QLCDNumber>
#include <QTimer>
#include <QTime>

class countdowntimer:public QLCDNumber{
    Q_OBJECT
private:
    QTimer* timer;
    QTime* timeValue;

public:
    countdowntimer(QWidget*, int, int);
    QTimer* getTimer();

public slots:
    void setDisplay();
};

#endif // COUNTDOWNTIMER_H
