#ifndef PLAYER_H
#define PLAYER_H
#include <stdlib.h>
#include "agent.h"
#include "room.h"
#include <QString>
#include <object.h>
#include <items.h>
#include <fixeditem.h>
#include <vector>
class player : public agent
{
public:
    player (QString  _name, room *, int h, int a);
    bool act();
    room *r1;
    QString getstr();
    void setdirc(QString x);
    void drop(items *);
    void pickup(items *);
    void dropfix(fixeditem *);
    void pickupfix(fixeditem *);
    QString printitem();
    QString printfixeditem();
    items * sitem(QString x);
    room *getcur();
    int getscore();
    fixeditem *sitemfix(QString x);
    void dropt(treasure *);
    void pickupt(treasure *);
    treasure *streasure(QString );
    QString printtreasure();
    void dropallfix();
     void dropall();
protected:
private:
   QString str="";
   QString dirc="";
   vector <items *> allitems;
   vector <fixeditem *> fixeditems;
   QString item="";
   int score=0;
   vector <treasure *> treasure_vec;
};

#endif // PLAYER_H
