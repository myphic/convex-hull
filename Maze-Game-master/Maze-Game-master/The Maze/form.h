#ifndef  FORM_H
#define  FORM_H
#include <iostream>
#include <string>
#include "room.h"
#include "agent.h"
#include "monster.h"
#include <time.h>
#include <QWidget>
#include <vector>
#include "player.h"
#include <QMediaPlayer>
#include "game.h"
class Widget;
namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);
    ~Form();
    Widget *mainwindow;
    void addallp(vector<player *>);
    void addallm(vector<monster *>);
    void run();
    void update (player *);
    bool p1=true;
    bool p11=true;
    bool p2=true;
    QString path;
private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_up_clicked();

    void on_start_clicked();

    void on_right_clicked();

    void on_left_clicked();

    void on_pushButton_4_clicked();

    void on_down_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::Form *ui;
    bool start =true;
   vector <player *> allp;
   vector <monster *> allm;
Game *g=new Game [1];
QMediaPlayer *steps;
   int curplayer=0;


};

#endif // FORM_H
