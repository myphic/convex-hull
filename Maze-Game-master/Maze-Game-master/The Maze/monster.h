#ifndef MONSTER_H
#define MONSTER_H
#include "room.h"
#include "agent.h"
using namespace std;


class monster : public agent
{
public:
    monster (QString  _name,room *,QString,int ,int );
    bool act();
    void setpl(agent *);
    bool splayer(agent *);
    int ai (string x,room *r ,int c ,agent *p );
    QString aidirc();
private:
   agent *pl;

};

#endif // MONSTER_H
