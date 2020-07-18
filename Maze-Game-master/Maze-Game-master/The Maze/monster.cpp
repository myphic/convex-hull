#include "monster.h"
#include <cstdlib>

monster :: monster(QString  _name="" , room *starting_room=0,QString _dis="",int h=0,int a=0)
{
    health=h;
    attak=a;
    name = _name;
    croom= starting_room;
    disc="monster  ";
    disc+=_dis;
    pl=NULL;
    croom->enter(this,0);
}
void monster::setpl(agent *p)
{
pl=p;
}
bool monster::splayer(agent *p)
{
 for(int i=4; i<6; i++)
{

if(croom->getoccupants()[i]!=NULL)
{
    if(croom->getoccupants()[i]->getname()==p->getname())
    {
        return true;
    }
}
}
    return false;
}
int monster ::ai (string x,room *r ,int c ,agent *p )
{
    int n=99;
    int e=99;
    int s=99;
    int w=99;
    int n1=99;
    int e1=99;
    int s1=99;
    int w1=99;
for(int i=4; i<6; i++)
{

if(r->getoccupants()[i]!=NULL)
{
    if(r->getoccupants()[i]->getname()==p->getname())
    {
        return c;
    }
}
}

        if(x!="n"&&r->getlinked("n")!=NULL)
        {
            n1=c+1;
            n=ai("s",r->getlinked("n"),n1,p);
        }
        if(x!="e"&&r->getlinked("e")!=NULL)
        {
            e1=c+1;
            e=ai("w",r->getlinked("e"),e1,p);
        }
        if(x!="s"&&r->getlinked("s")!=NULL)
        {
            s1=c+1;
            s=ai("n",r->getlinked("s"),s1,p);
        }
        if(x!="w"&&r->getlinked("w")!=NULL)
        {
            w1=c+1;
            w=ai("e",r->getlinked("w"),w1,p);
        }
        else
        {
           if(n<=e&&n<=s&&n<=w)
           {
               return n;
           }
           else if (e<=n&&e<=s&&e<=w)
           {
               return e;
           }
           else if (s<=n&&s<=e&&s<=w)
           {
               return s;
           }
           else if (w<=n&&w<=s&&w<=e)
           {
               return w;
           }

        }
    }
QString monster::aidirc()
{
int n=99;
int e=99;
int s=99;
int w=99;
if(croom->getlinked("n")!=NULL&&croom->getname()!="Main Gate this is the exit")
    {
     n=ai ("s",croom->getlinked("n") ,0 ,pl );
    }
if(croom->getlinked("e")!=NULL)
    {
        e=ai ("w",croom->getlinked("e") ,0,pl );
    }
if(croom->getlinked("s")!=NULL)
    {
        s=ai ("n",croom->getlinked("s") ,0 ,pl );
    }
if(croom->getlinked("w")!=NULL)
    {
        w=ai ("e",croom->getlinked("w") ,0 ,pl );
    }

         if(n<=e&&n<=s&&n<=w)
           {
               return "n";
           }
           else if (e<=n&&e<=s&&e<=w)
           {
               return "e";
           }
           else if (s<=n&&s<=e&&s<=w)
           {
               return "s";
           }
           else if (w<=n&&w<=s&&w<=e)
           {
               return "w";
           }
           else
            {
                return "";
            }
    }
bool monster::act()
{
if(pl==NULL)
{
    room temp("","");
    int n = rand() % 4;
    QString direction;
    switch(n)
    {
    case 0:
        direction = "n";
        break;
    case 1:
        direction = "s";
        break;
    case 2:
        direction = "w";
        break;
    case 3:
        direction = "e";
        break;
    }
    if(croom->getlinked(direction) != NULL)
    {
        temp=(*croom->getlinked(direction));
        if((temp.enter(this,0)==true)&&(temp.getname()!="Main Gate this is the exit"))

        {
            temp.leave(this);
            croom->leave(this);
            croom = croom->getlinked(direction);
            croom->enter(this,0);
        }
    }
}
else
{room temp("","");
 QString direction;
     if(!splayer(pl))
     {
         direction = aidirc();
     }
    if(croom->getlinked(direction) != NULL)
    {
        temp=(*croom->getlinked(direction));
        if((temp.enter(this,0)==true)&&(temp.getname()!="Main Gate this is the exit"))

        {
            temp.leave(this);
            croom->leave(this);
            croom = croom->getlinked(direction);
            croom->enter(this,0);
        }
    }
}
    return true;
}
