#include "player.h"
#include <conio.h>
#include <windows.h>
player::player(QString _name="player" , room *curroom=0,int h=0,int a=0)
{
    health=h;
    attak=a;
    name = _name ;
    croom =curroom;
    disc="player";
    r1=croom;
    croom->enter(this,5);
    str+="welcom  "+name+" its your turn"+"\n**********************************************************";
    str+="\nyou in "+croom->getname()+"."+"\n\n************************\n\n"+croom->getdis()+"\n\nSo you can go \n\n";
    str+=croom->printlinked();
    str+="\n \nand there is\n";
    str+=croom->printoccupants();
   str+=printfixeditem()+printitem();
   str+=croom->printfixeditem()+croom->printitem();
     str+=printtreasure();
        str+=croom->printtreasure();
   }
QString player::getstr()
{
    return str;
}
void player::setdirc(QString x)
{
    dirc=x;
}
room *player::getcur()
{return croom;
}
int player::getscore()
{
    return score;
}
void player::pickup(items *x)
{
if(allitems.size()<2)
{allitems.push_back(x);
health+=x->geth();
attak+=x->geta();}
}
void player::drop(items *x)
{
for(int i=0;i<allitems.size();i++)
{
if(allitems[i]==x)
{vector<items *>::iterator it;
it=(allitems.begin()+i);
allitems.erase(it);
health-=x->geth();
attak-=x->geta();
}
}
}
void player::pickupfix(fixeditem *x)
{
fixeditems.push_back(x);
health+=x->geth();
attak+=x->geta();
}
void player::dropfix(fixeditem *x)
{
for(int i=0;i<fixeditems.size();i++)
{
if(fixeditems[i]==x)
{vector<fixeditem *>::iterator it;
it=(fixeditems.begin()+i);
fixeditems.erase(it);
health-=x->geth();
attak-=x->geta();
}
}
}
void player::dropallfix()
{
for(int i=0;i<fixeditems.size();i++)
{fixeditem *x;
{vector<fixeditem *>::iterator it;
x=fixeditems[i];
it=(fixeditems.begin()+i);
croom->dropfix(x);
fixeditems.erase(it);
health-=x->geth();
attak-=x->geta();
}
}
}
void player::dropall()
{
for(int i=0;i<allitems.size();i++)
{items *x;
{vector<items *>::iterator it;
x=allitems[i];
it=(allitems.begin()+i);
croom->drop(x);
allitems.erase(it);
health-=x->geth();
attak-=x->geta();
}
}
for(int i=0;i<treasure_vec.size();i++)
{treasure *x;
{vector<treasure *>::iterator it;
x=treasure_vec[i];
it=(treasure_vec.begin()+i);
croom->dropt(x);
treasure_vec.erase(it);
}
}
}
QString player::printitem()
{QString x="";
if(allitems.size()>0)
{x+="\n\n and you have in your bag \n******************************\n\n";}
for(int i=0;i<allitems.size();i++)
{
x+=(allitems[i]->getn()+"    "+allitems[i]->getd()+"\n");
}
return x;
}
QString player::printfixeditem()
{QString x="";
if(fixeditems.size()>0)
{x+="\n\n and you can use it's items \n******************************\n\n";}
for(int i=0;i<fixeditems.size();i++)
{
x+=(fixeditems[i]->getn()+"    "+fixeditems[i]->getd()+"\n");
}
return x;
}
QString player::printtreasure()
{
QString x="";
if(treasure_vec.size()>0)
{x+="\n\n and you have this clues in your bag \n******************************\n\n";}
for(int i=0;i<treasure_vec.size();i++)
{
x+=(treasure_vec[i]->getname()+" \n");
}
return x;
}
items  *player::sitem(QString x)
{
for(int i=0; i < allitems.size();i++)
{
if((allitems[i]->getn())== x)
{return allitems[i];}
}
return NULL;
}
fixeditem  *player::sitemfix(QString x)
{
for(int i=0; i < fixeditems.size();i++)
{
if((fixeditems[i]->getn())==x)
{return fixeditems[i];}
}
return NULL;
}
treasure *player::streasure(QString x)
{
{
for(int i=0; i < treasure_vec.size();i++)
{
if((treasure_vec[i]->getname())==x)
{return treasure_vec[i];}
}
return NULL;
}
}
void player::pickupt(treasure * tr)
{
treasure_vec.push_back(tr);
score++;

}
void player::dropt(treasure * tr)
{

for (int i=0 ;i<treasure_vec.size();i++)
    {if(treasure_vec[i]==tr)
    {treasure_vec.erase(treasure_vec.begin()+i);}
    }
score--;
}
bool player ::act()
{
QString y="";
    y=dirc;
    if(y=="esc")
    {
        str=name +" , you are out";
        dropallfix();
        croom->leave(this);
        return false;

    }


    if (croom->getlinked(y)==NULL)
    {  str="";
        str+="welcom  "+name+" its your turn"+"\n**********************************************************";
        str+="\nyou in "+croom->getname()+"."+"\n\n************************\n\n"+croom->getdis()+"\n\nSo you can go \n\n";
        str+=croom->printlinked();
        str+="\n \nand there is\n";
        str+=croom->printoccupants();
        str+=printfixeditem()+printitem();
        str+=croom->printfixeditem()+croom->printitem();
        str+=printtreasure();
        str+=croom->printtreasure();
        str+="there is no way here \n";
        return true;

    }
    room temp("",""),temp2("","");

    croom->leave(this);
    temp2=(*croom);
    temp=(*croom->getlinked(y));
     if((temp.enter(this,5)==true))

    {
    if(temp2.getname()!=temp.getname())
        {dropallfix();}
        croom=croom->getlinked(y);
        if(croom->getname()=="Main Gate this is the exit")
        { str=name +" , you are out\n";
            return false;
        }

        croom->enter(this,5);
        QString y="";
        str="";
        str+="welcom  "+name+" its your turn"+"\n**********************************************************";
        str+="\nyou in "+croom->getname()+"."+"\n\n************************\n\n"+croom->getdis()+"\n\nSo you can go \n\n";
        str+=croom->printlinked();
        str+="\n \nand there is\n";
        str+=croom->printoccupants();
        str+=printfixeditem()+printitem();
        str+=croom->printfixeditem()+croom->printitem();
        str+=printtreasure();
        str+=croom->printtreasure();
        return true;
    }
    else
    {
        str="full room\n";
        croom->enter(this,5);
        return true;
    }



}
