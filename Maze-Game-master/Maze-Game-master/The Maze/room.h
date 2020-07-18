#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include <QString>
#include <vector>
#include "fixeditem.h"
#include "items.h"
#include "treasure.h"
using namespace std;
class agent;
class room
{
public:

    room(QString , QString );
    QString getname()const;
    QString getdis()const;
    void link(room *, QString );
    room *getlinked(QString);
    QString printlinked()const;
    bool enter (agent *, int c);
    void leave(agent *);
    QString printoccupants();
    void drop(items *);
    void pickup(items *);
    QString printitem();
    QString printfixeditem();
    void dropfix(fixeditem *);
    void pickupfix(fixeditem *);
    items * sitem(QString x);
    fixeditem *sitemfix(QString x);
    vector <agent *> getoccupants();
    void dropt(treasure *);
    void pickupt(treasure *);
    treasure *streasure(QString );
    QString printtreasure();
    QString photopath;

private:
    QString name, dis;
    room *north;
    room *east;
    room *south;
    room *west;
    vector <agent*> occupants;
    vector <items *> allitems;
    vector <fixeditem *> fixeditems;
    vector <treasure *> treasure_vec;


};

#endif // ROOM_H
