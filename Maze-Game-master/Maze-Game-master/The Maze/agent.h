#ifndef AGENT_H
#define AGENT_H
#include "room.h"
#include <iostream>
#include <QString>
class agent
{
public:
    QString getname();
    QString getdisc();
    virtual bool act() = 0;
    int gethealth();
    int getattack();
protected:
    int health ;
    int attak ;
    room *croom;
    QString name ;
    QString disc;



private:
};

#endif // AGENT_H
