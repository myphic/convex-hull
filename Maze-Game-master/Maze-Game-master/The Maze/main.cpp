#include "widget.h"
#include <QApplication>
#include <QString>
#include "room.h"
#include "monster.h"
#include "player.h"
#include <time.h>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include "items.h"
#include "fixeditem.h"
int main(int argc, char *argv[])
{


    QApplication a(argc, argv);
    QString path="C:/Users/hp/Desktop/project/";
    srand(time(NULL));
    room r1 ("Garden"      , "The Garden*s wall are surrounded by tree yellow leaves there are few flower beds near the main gate there are 2 door one of them is a wooden door the other is big fancy door leads to the main hall");
    r1.photopath="garden.jpg";
    room r2 ("Main hall"   , "The Main hall is so big with along red carpet on the floor there are a few golden statues near each wall there are photos of people hangared on the wall .one of them for a family of five persons a mother ,a father ,2 sons and a daughter no one in the room but u can hear  few steps leading to upstairs");
    r2.photopath="garden.jpg";
    room r3 ("Kitchen"     , "The Kitchen*s floor is wooden floor which causes a creaking sound when u step on it there is on old stove , fridge and silver plates there is a window but it is too dark to see what is outside");
    r3.photopath="garden.jpg";
    room r4 ("Guest room"  , "The Room is large with more photos of family on the walls there is a piano at the end of the room when you go near it you can hear the music you can see some shadows on the walls even though there is no one here");
    r4.photopath="garden.jpg";
    room r5 ("Upstairs"    , "Upstairs there is a hallway leading to more rooms");
    r5.photopath="garden.jpg";
    room r6 ("Bed room 1"  , "There is a king size bed, golden sword on the wall a photo frame but there is no photo int it the doors of the cup board is opened but it is too dark to see what is there you can see that it is raining through a window u can here the thunder");
    r6.photopath="garden.jpg";
    room r7 ("Bed room 2"  , "every thing in the room is pink pink bed pink room  pink wall pink curtain there are a few dolls  that look a little creepy on of them frequently opens and close its eye and u can hear a little girl*s laughter");
    r7.photopath="garden.jpg";
    room r8 ("Rest room"   , "The water in the shower is running and you cannot stop it when you look through the window you can see that it its sunny day but you hear the wind*s sound you can hear a little saying \"brother ,what are you doing here?!\" .is it the  same girl from before?!! you cannot see anyone there but you see a trial of blood leading at side the room");
    r8.photopath="garden.jpg";
    room r9 ("Unknown room", "the door  to the room is made of heavy metal and there are 3 locks ,2 of them are broken ,in side the room there are 2 beds there are a chain beside each one . there 2 nightstands on one of them there are multiple book and on other there is Rubik*s cube and few other games");
    r9.photopath="garden.jpg";
    room r10("Dinning room", "you can see a big table and few plates on it with cold food two of the chairs have chains attached to them ");
    r10.photopath="garden.jpg";
    room r11("Basement"    , "it is too dark to see anything ");
    r11.photopath="garden.jpg";
    room exit("Main Gate this is the exit","");
    r1.link(&exit,"n");
    r1.link(&r2,"s");
    r2.link(&r1,"n");
    r1.link(&r11,"w");
    r11.link(&r1,"e");
    r2.link(&r3,"e");
    r3.link(&r2,"w");
    r2.link(&r4,"w");
    r4.link(&r2,"e");
    r2.link(&r5,"s");
    r5.link(&r2,"n");
    r5.link(&r6,"e");
    r6.link(&r5,"w");
    r5.link(&r7,"w");
    r7.link(&r5,"e");
    r5.link(&r10,"s");
    r10.link(&r5,"n");
    r6.link(&r9,"s");
    r9.link(&r6,"n");
    r7.link(&r8,"s");
    r8.link(&r7,"n");
    items rubekscube ("rubek*s_cube","Unsolved But that advantage may be",100,0);
    items pliers ("pliers","It's a little rust, but may greatly benefit",25,25);
    items Woolball ("Wool_ball","Maybe the cat wants to play only used this ball",100,100);
    fixeditem lawnmowers ("lawnmowers","You can not believe how scared monsters of this machine",0,25);
    fixeditem SilverChair ("Silver_Chair","It is said that silver Tove monsters Is this really true",25,25);
    fixeditem ClosedBox ("Closed_Box","What may be inside",25,25);
    treasure key("Steel_Key");
    treasure map("Map_hidden_rooms");
    treasure Necklace("Necklace_killed_Ghost");
    r1.drop(& pliers);
    r1.dropfix(&lawnmowers);
    r1.dropt(&key);
    r2.drop(&Woolball);
    r2.drop(&rubekscube);
    r4.dropt(&map);
    r3.dropfix(&SilverChair);
    r9.dropfix(&ClosedBox);
    r7.dropt(&Necklace);
    vector <player *>players;
    vector <monster *>monsters;
    monster m1("shadow 1                ",&r3, "moving around the kitchen you can hear it*s footsteps and a cutting sound from time to time",50,50);
    monster m2("girl in pink            ",&r5, "a little girl laughing loudly while running and hiding behind the furniture                ",50,50);
    monster m3("shadow 2                ",&r4, "playing piano and when it stops you can hear it weeping                                    ",50,50);
    monster m4("shadow 3                ",&r10,"a shadow that holding book turning its pages silently                                      ",50,50);
    monster m5("the boy with white hair ",&r9, "boy holding rubek*s cube and looking at you                                                ",100,100);
    monster m6("black cat               ",&r9, "a cat moving around you                                                                    ",100,100);
    player p1( "wonka                   ",&r1,50,50);
    player p2( "eva                     ",&r1,50,50);
    m6.setpl(&p1);
    m5.setpl(&p2);

    monsters.push_back(&m1);
    monsters.push_back(&m2);
    monsters.push_back(&m3);
    monsters.push_back(&m4);
    monsters.push_back(&m5);
    monsters.push_back(&m6);
    players.push_back(&p1);
    players.push_back(&p2);

    QMediaPlayer *player0;
    player0 = new QMediaPlayer;
    QMediaPlaylist *playlist0;
    playlist0 = new QMediaPlaylist;
    playlist0->addMedia(QUrl(path+"-Avatar Soundtrack-.mp3"));
    playlist0->setPlaybackMode(QMediaPlaylist::Loop);




    player0->setPlaylist(playlist0);
    player0->setVolume(75);
    player0->play();


    Widget w;
    w.addallp(players);
    w.addallm(monsters);
    w.path=path;
    w.run();
    w.showFullScreen();

    return a.exec();


}

