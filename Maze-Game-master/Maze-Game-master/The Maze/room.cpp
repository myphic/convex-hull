#include "room.h"
#include <iostream>
#include "agent.h"
#include <stdlib.h>
using namespace std;
room::room( QString n, QString d)
{
    name = n;
    dis = d;
    north=NULL;
    east=NULL;
    south=NULL;
    west=NULL;
    occupants.push_back(NULL);
    occupants.push_back(NULL);
    occupants.push_back(NULL);
    occupants.push_back(NULL);
    occupants.push_back(NULL);
    occupants.push_back(NULL);
}
items  *room::sitem(QString x)
{
for(int i=0; i < allitems.size();i++)
{
if((allitems[i]->getn())==x)
{return allitems[i];}
}
return NULL;
}
fixeditem  *room::sitemfix(QString x)
{
for(int i=0; i < fixeditems.size();i++)
{
if((fixeditems[i]->getn())==x)
{return fixeditems[i];}
}
return NULL;
}
void room::drop(items *x)
{
allitems.push_back(x);
}
void room::dropfix(fixeditem *x)
{
fixeditems.push_back(x);
}

QString room::printitem()
{QString x="";
if(allitems.size()>0)
{x+="\n\n you will find in this room this items  \n********************************************\n\n";}
for(int i=0;i<allitems.size();i++)
{
x+=(allitems[i]->getn()+"    "+allitems[i]->getd()+"\n");
}
return x;
}
QString room::printfixeditem()
{QString x="";
if(fixeditems.size()>0)
{x+="\n\n you see some tools may be help you \n***************************************\n\n";}
for(int i=0;i<fixeditems.size();i++)
{
x+=(fixeditems[i]->getn()+"    "+fixeditems[i]->getd()+"\n");
}
return x;
}
void room::pickupfix(fixeditem *x)
{
for(int i=0;i<fixeditems.size();i++)
{if(fixeditems[i]==x)
{vector<fixeditem *>::iterator it;
it=(fixeditems.begin()+i);
fixeditems.erase(it);}
}
}

void room::pickup(items *x)
{
for(int i=0;i<allitems.size();i++)
{if(allitems[i]==x)
{vector<items *>::iterator it;
it=(allitems.begin()+i);
allitems.erase(it);}
}
}
QString room::getname()const
{
    return name;
}
QString room::getdis()const
{
    return dis;
}
void room::link(room *r1, QString d)
{
    if (d=="n")
    {
        north=r1;
    }
    else if (d=="s")
    {
        south=r1;
    }
    else if (d=="e")
    {
        east=r1;
    }
    else if (d=="w")
    {
        west=r1;
    }

}
room *room::getlinked( QString d)
{
    if (d=="n")
        return north;
    else if (d=="s")
        return south;
    else if (d=="e")
        return east;
    else if (d=="w")
        return west;
    else
        return this;


}

QString room::printlinked()const
{
    QString x="";
    if (north!=NULL)
    {
        x+=" up     -->  "+north->getname()+"\n";
    }
    if (south!=NULL)
    {
        x+=" down   -->  "+south->getname()+"\n";
    }
    if (east!=NULL)
    {
        x+=" right  -->  "+east->getname()+"\n";
    }
    if (west!=NULL)
    {
        x+=" left   -->  "+west->getname()+"\n";
    }
    return x;

}
bool room::enter(agent *a,int c=0)
{
    agent *b;
    if(c==0)
    {
        for(int i=0; i<4; i++)
        {
            b=occupants[i];

            if(b==NULL)
            {
                occupants[i]=a;
                return true;
                break;
            }

        }

        return false;
    }
    else if (c==5)
    {
        for(int i=4; i<6; i++)
        {
            b=occupants[i];
            if(b==NULL)
            {
                occupants[i]=a;
                return true;
                break;
            }
        }
        return false;
    }

}
void room::leave(agent *a)
{
    agent *b;
    for(int i=0; i<6; i++)
    {
        b=occupants[i];
        if(b==a)
        {
            occupants[i]=NULL;
        }

    }
}
QString room::printoccupants()
{
    QString x="";
    if(occupants[0]!=NULL)
    {
        x+=occupants[0]->getname()+"     "+occupants[0]->getdisc()+"\n";
    }

    if(occupants[1]!=NULL)
    {
        x+=occupants[1]->getname()+"     "+occupants[1]->getdisc()+"\n";
    }
    if(occupants[2]!=NULL)
    {
        x+=occupants[2]->getname()+"     "+occupants[2]->getdisc()+"\n";
    }

    if(occupants[3]!=NULL)
    {
        x+=occupants[3]->getname()+"     "+occupants[3]->getdisc()+"\n";
    }
    if(occupants[4]!=NULL)
    {
        x+=occupants[4]->getname()+"     "+occupants[4]->getdisc()+"\n";
    }
    if(occupants[5]!=NULL)
    {
        x+=occupants[5]->getname()+"     "+occupants[5]->getdisc()+"\n";
    }
    return x;
}
treasure *room::streasure(QString x)
{

for(int i=0; i < treasure_vec.size();i++)
{
if((treasure_vec[i]->getname())==x)
{return treasure_vec[i];}
}
return NULL;
}
QString room::printtreasure()
{
QString x="";
if(treasure_vec.size()>0)
{x+="\n\n and you found in the room \n******************************\n\n";}
for(int i=0;i<treasure_vec.size();i++)
{
x+=(treasure_vec[i]->getname()+" \n");
}
return x;
}

vector <agent *> room::getoccupants()
{
    return occupants;
}
void room::pickupt(treasure * tr)
{
for (int i=0 ;i<treasure_vec.size();i++)
    {if(treasure_vec[i]==tr)
    {treasure_vec.erase(treasure_vec.begin()+i);}
}
}
void room::dropt(treasure * tr)
{

treasure_vec.push_back(tr);

}
