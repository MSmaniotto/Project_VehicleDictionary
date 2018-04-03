#include "GUI/header/countdowntimer.h"

countdowntimer::countdowntimer(QWidget* parent, int minutes, int seconds){
    timer=new QTimer;
    timeValue=new QTime(0,minutes, seconds);
    this->setParent(parent);
    this->display(timeValue->toString());
    connect(timer, SIGNAL(timeout()), this, SLOT(setDisplay()));
}

void countdowntimer::setDisplay(){
    if(timeValue->minute()==0&&timeValue->second()==0)
        parentWidget()->close();
    timeValue->setHMS(0, timeValue->addSecs(-1).minute(), timeValue->addSecs(-1).second());
    display(timeValue->toString());

}

QTimer* countdowntimer::getTimer(){
    return timer;
}
