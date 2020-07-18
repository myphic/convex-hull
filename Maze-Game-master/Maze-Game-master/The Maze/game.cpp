#include "game.h"
#include "agent.h"

int Game::wol(player * x)
{
    vector <agent *> occupants2;
    occupants2=x->getcur()->getoccupants();
for(int i=0;i<4;i++)
{
  if(occupants2[i]!=NULL)
   { if(occupants2[i]->getattack()>x->gethealth())
    {
       x->dropall();
        return 0;
    }

}
}
if(x->getscore()>=3)
    {
        x->dropall();
        return 1;
    }
else
{return 3;}

}
