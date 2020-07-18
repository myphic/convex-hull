#ifndef GAME_H
#define GAME_H
#include "room.h"
#include"player.h"
#include"monster.h"
class Game
{
public:
    room *monster_room;
    int wol(player *);
};

#endif // GAME_H
