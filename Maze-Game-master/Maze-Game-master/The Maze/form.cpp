#include "form.h"
#include "ui_form.h"
#include"widget.h"
#include"QString"
#include "items.h"
#include "room.h"
#include "treasure.h"

#include "QMessageBox"
#include "fixeditem.h"
#include "QtGui"


Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);


}
void Form::update (player *x)
{
    QString s,h,a;
    s= QString::number(x->getscore());
    h= QString::number(x->gethealth());
    a= QString::number(x->getattack());
    ui->score->setText(s);
    ui->health->setText(h);
    ui->attake->setText(a);
   /* QPixmap pix2(path+x->getcur()->photopath);
    int h2=ui->label_12->height();
    int w2=ui->label_12->width();
    ui->label_12->setPixmap(pix2.scaled(w2*20,h2*20,Qt::KeepAspectRatio));
*/
}
void Form ::run()
{if(p1==true)
{
    QString x;
        QPixmap pix(path+"dracula.png");
    int h=ui->label_7->height();
    int w=ui->label_7->width();
    ui->label_7->setPixmap(pix.scaled(w*1.009,h*1.009,Qt::KeepAspectRatio));
    QPixmap pix2(path+allp[0]->getcur()->photopath);
    int h2=ui->label_12->height();
    int w2=ui->label_12->width();
    ui->label_12->setPixmap(pix2.scaled(w2*20,h2*20,Qt::KeepAspectRatio));

    steps = new QMediaPlayer;
    steps->setMedia(QUrl::fromLocalFile(path+"Footsteps.mp3"));
    steps->setVolume(100);
    update(allp[0]);
    x=allp[0]->getstr();
    ui->textBrowser->setText(x);
}
else if (p2==true)
{
    QString x;
        QPixmap pix(path+"dracula.png");
    int h=ui->label_7->height();
    int w=ui->label_7->width();
    ui->label_7->setPixmap(pix.scaled(w*1.009,h*1.009,Qt::KeepAspectRatioByExpanding));
    QPixmap pix2(path+allp[0]->getcur()->photopath);
    int h2=ui->label_12->height();
    int w2=ui->label_12->width();
    ui->label_12->setPixmap(pix2.scaled(w2*20,h2*20,Qt::KeepAspectRatioByExpanding));

    steps = new QMediaPlayer;
    steps->setMedia(QUrl::fromLocalFile(path+"Footsteps.mp3"));
    steps->setVolume(100);
    update(allp[1]);
    x=allp[1]->getstr();
    ui->textBrowser->setText(x);
}
else
{
 QPixmap pix(path+"dracula.png");
    int h=ui->label_7->height();
    int w=ui->label_7->width();
    ui->label_7->setPixmap(pix.scaled(w*1.009,h*1.009,Qt::KeepAspectRatioByExpanding));
    QPixmap pix2(path+allp[0]->getcur()->photopath);
    int h2=ui->label_12->height();
    int w2=ui->label_12->width();
    ui->label_12->setPixmap(pix2.scaled(w2*20,h2*20,Qt::KeepAspectRatioByExpanding));

    steps = new QMediaPlayer;
    steps->setMedia(QUrl::fromLocalFile(path+"Footsteps.mp3"));
    steps->setVolume(100);
ui->textBrowser->setText("all player out the game please start a new game");
}
}

Form::~Form()
{
    delete ui;
}

void Form::addallp(vector <player *> x)
{
    allp=x;
}

void Form::addallm(vector <monster *> x)
{
    allm=x;
}

void Form::on_pushButton_5_clicked()
{   mainwindow-> p1=p1;
    mainwindow-> p11=p11;
    mainwindow->p2=p2;
    mainwindow->show();
    this->close();

}

void Form::on_pushButton_6_clicked()
{
}

void Form::on_start_clicked()
{

    if(p1&&(!p2))
    {
        allp[0]->setdirc("esc");
        p1=allp[0]->act();
        allp[1]->act();
        QString x;
        x=allp[0]->getstr();
        ui->textBrowser->setText(x);
        update(allp[0]);
        curplayer=0;

    }
    else if(p2&&(!p1))
    {
        allp[1]->setdirc("esc");
        p2=allp[1]->act();
        allp[0]->act();
        QString x;
        x=allp[1]->getstr();
        ui->textBrowser->setText(x);
        update(allp[1]);
        curplayer=1;
    }
    else if(p1&&p2)
    {
        if(curplayer==0)
        {
            allp[0]->setdirc("esc");
            p1=allp[0]->act();
            allp[1]->act();
            QString x;
            x=allp[1]->getstr();
            ui->textBrowser->setText(x);
            update(allp[1]);
            curplayer=1;
        }
        else if(curplayer==1)
        {
            allp[1]->setdirc("esc");
            p2=allp[1]->act();
            allp[0]->setdirc("");
            allp[1]->setdirc("");
            allp[0]->act();
            allp[1]->act();
            QString x;
            x=allp[0]->getstr();
            ui->textBrowser->setText(x);
            update(allp[0]);
            curplayer=0;

        }
    }

    else
    { ui->textBrowser->setText("all player out the game please start a new game");
    }

}

void Form::on_up_clicked()  //up button
{    if(p1&&(!p2))
    {
        allp[0]->setdirc("n");
        p1=allp[0]->act();
        allp[0]->setdirc("");
            allp[1]->setdirc("");
            allp[0]->act();
            allp[1]->act();
        for(int i=0 ; i<6;i++)
        {
            allm[i]->act();
        }
        if (g->wol(allp[0])==1)
        {
            allp[0]->setdirc("esc");
            p1=allp[0]->act();
            allp[0]->setdirc("");
            allp[1]->setdirc("");
            allp[0]->act();
            allp[1]->act();
            QMessageBox::information(this,"winner","wonka is winner");
        }
        else if (g->wol(allp[0])==0)
        {
            allp[0]->setdirc("esc");
            p1=allp[0]->act();
            allp[0]->setdirc("");
            allp[1]->setdirc("");
            allp[0]->act();
            allp[1]->act();
            QMessageBox::information(this,"winner","wonka is loser");
        }

        QString x;
        x=allp[0]->getstr();
        update(allp[0]);
        ui->textBrowser->setText(x);
        curplayer=0;

    }
    else if(p2&&(!p1))
    {
        allp[1]->setdirc("n");
        p2=allp[1]->act();
        allp[0]->setdirc("");
            allp[1]->setdirc("");
            allp[0]->act();
            allp[1]->act();
        for(int i=0 ; i<6;i++)
        {
            allm[i]->act();
        }
        if (g->wol(allp[1])==1)
        {
            allp[1]->setdirc("esc");
            p2=allp[1]->act();
            allp[0]->setdirc("");
            allp[1]->setdirc("");
            allp[0]->act();
            allp[1]->act();
            QMessageBox::information(this,"winner","eva is winner");
        }
        else if (g->wol(allp[1])==0)
        {
            allp[1]->setdirc("esc");
            p2=allp[1]->act();
            allp[0]->setdirc("");
            allp[1]->setdirc("");
            allp[0]->act();
            allp[1]->act();
            QMessageBox::information(this,"loser","eva is loser");
        }
        QString x;
        x=allp[1]->getstr();
        update(allp[1]);
        ui->textBrowser->setText(x);
        curplayer=1;
    }
    else if(p1&&p2)
    {
        if(curplayer==0)
        {
            allp[0]->setdirc("n");
            p1=allp[0]->act();
            allp[0]->setdirc("");
            allp[1]->setdirc("");
            allp[0]->act();
            allp[1]->act();
            /*for(int i=0 ; i<6;i++)
            {
                allm[i]->act();
            }*/
            if (g->wol(allp[0])==1)
            {
                allp[0]->setdirc("esc");
                p1=allp[0]->act();
                allp[0]->setdirc("");
            allp[1]->setdirc("");
            allp[0]->act();
            allp[1]->act();
                QMessageBox::information(this,"winner","wonka is winner");
            }
            else if (g->wol(allp[0])==0)
            {
                allp[0]->setdirc("esc");
                p1=allp[0]->act();
                allp[0]->setdirc("");
            allp[1]->setdirc("");
            allp[0]->act();
            allp[1]->act();
                QMessageBox::information(this,"winner","wonka is loser");
            }

            QString x;
            x=allp[1]->getstr();
            update(allp[1]);
            ui->textBrowser->setText(x);
            curplayer=1;
        }
        else if(curplayer==1)
        {
            allp[1]->setdirc("n");
            p2=allp[1]->act();
            allp[0]->setdirc("");
            allp[1]->setdirc("");
            allp[0]->act();
            allp[1]->act();
            for(int i=0 ; i<6;i++)
            {
                allm[i]->act();
            }
            if (g->wol(allp[1])==1)
            {
                allp[1]->setdirc("esc");
                p2=allp[1]->act();
                allp[0]->setdirc("");
            allp[1]->setdirc("");
            allp[0]->act();
            allp[1]->act();
                QMessageBox::information(this,"winner","eva is winner");
            }
            else if (g->wol(allp[1])==0)
            {
                allp[1]->setdirc("esc");
                p2=allp[1]->act();
                allp[0]->setdirc("");
            allp[1]->setdirc("");
            allp[0]->act();
            allp[1]->act();
                QMessageBox::information(this,"loser","eva is loser");
            }
            QString x;
            x=allp[0]->getstr();
            update(allp[0]);
            ui->textBrowser->setText(x);
            curplayer=0;
        }
    }

    else
    { ui->textBrowser->setText("all player out the game please start a new game");
    }
     steps->play();

}

void Form::on_right_clicked() //right button
{
    if(p1&&(!p2))
    {
        allp[0]->setdirc("e");
        p1=allp[0]->act();
        for(int i=0 ; i<6;i++)
        {
            allm[i]->act();
        }
        if (g->wol(allp[0])==1)
        {
            allp[0]->setdirc("esc");
            p1=allp[0]->act();
            allp[0]->setdirc("");
            allp[1]->setdirc("");
            allp[0]->act();
            allp[1]->act();
            QMessageBox::information(this,"winner","wonka is winner");
        }
        else if (g->wol(allp[0])==0)
        {
            allp[0]->setdirc("esc");
            p1=allp[0]->act();
            allp[0]->setdirc("");
            allp[1]->setdirc("");
            allp[0]->act();
            allp[1]->act();
            QMessageBox::information(this,"winner","wonka is loser");
        }

        QString x;
        x=allp[0]->getstr();
        update(allp[0]);
        ui->textBrowser->setText(x);
        curplayer=0;

    }
    else if(p2&&(!p1))
    {
        allp[1]->setdirc("e");
        p2=allp[1]->act();
        for(int i=0 ; i<6;i++)
        {
            allm[i]->act();
        }
        if (g->wol(allp[1])==1)
        {
            allp[1]->setdirc("esc");
            p2=allp[1]->act();
            allp[0]->setdirc("");
            allp[1]->setdirc("");
            allp[0]->act();
            allp[1]->act();
            QMessageBox::information(this,"winner","eva is winner");
        }
        else if (g->wol(allp[1])==0)
        {
            allp[1]->setdirc("esc");
            p2=allp[1]->act();
            allp[0]->setdirc("");
            allp[1]->setdirc("");
            allp[0]->act();
            allp[1]->act();
            QMessageBox::information(this,"loser","eva is loser");
        }
        QString x;
        x=allp[1]->getstr();
        update(allp[1]);
        ui->textBrowser->setText(x);
        curplayer=1;
    }
    else if(p1&&p2)
    {
        if(curplayer==0)
        {
            allp[0]->setdirc("e");
            p1=allp[0]->act();
        /*    for(int i=0 ; i<6;i++)
            {
                allm[i]->act();
            }*/
            if (g->wol(allp[0])==1)
            {
                allp[0]->setdirc("esc");
                p1=allp[0]->act();
                allp[0]->setdirc("");
            allp[1]->setdirc("");
            allp[0]->act();
            allp[1]->act();
                QMessageBox::information(this,"winner","wonka is winner");
            }
            else if (g->wol(allp[0])==0)
            {
                allp[0]->setdirc("esc");
                p1=allp[0]->act();
                allp[0]->setdirc("");
            allp[1]->setdirc("");
            allp[0]->act();
            allp[1]->act();
                QMessageBox::information(this,"winner","wonka is loser");
            }

            QString x;
            x=allp[1]->getstr();
            update(allp[1]);
            ui->textBrowser->setText(x);
            curplayer=1;
        }
        else if(curplayer==1)
        {

            allp[1]->setdirc("e");
            p2=allp[1]->act();
            allp[0]->setdirc("");
            allp[1]->setdirc("");
            allp[0]->act();
            allp[1]->act();
            for(int i=0 ; i<6;i++)
            {
                allm[i]->act();
            }
            if (g->wol(allp[1])==1)
            {
                allp[1]->setdirc("esc");
                p2=allp[1]->act();
                allp[0]->setdirc("");
            allp[1]->setdirc("");
            allp[0]->act();
            allp[1]->act();
                QMessageBox::information(this,"winner","eva is winner");
            }
            else if (g->wol(allp[1])==0)
            {
                allp[1]->setdirc("esc");
                p2=allp[1]->act();
                allp[0]->setdirc("");
                allp[1]->setdirc("");
                allp[0]->act();
                allp[1]->act();
                QMessageBox::information(this,"loser","eva is loser");
            }
            QString x;
            x=allp[0]->getstr();
            update(allp[0]);
            ui->textBrowser->setText(x);
            curplayer=0;
        }
    }

    else
    { ui->textBrowser->setText("all player out the game please start a new game");
    }
    steps->play();
}

void Form::on_left_clicked() //left button
{
    if(p1&&(!p2))
    {
        allp[0]->setdirc("w");
        p1=allp[0]->act();
        for(int i=0 ; i<6;i++)
        {
            allm[i]->act();
        }
        if (g->wol(allp[0])==1)
        {
            allp[0]->setdirc("esc");
            p1=allp[0]->act();
            allp[0]->setdirc("");
            allp[1]->setdirc("");
            allp[0]->act();
            allp[1]->act();
            QMessageBox::information(this,"winner","wonka is winner");
        }
        else if (g->wol(allp[0])==0)
        {
            allp[0]->setdirc("esc");
            p1=allp[0]->act();
            allp[0]->setdirc("");
            allp[1]->setdirc("");
            allp[0]->act();
            allp[1]->act();
            QMessageBox::information(this,"winner","wonka is loser");
        }

        QString x;
        x=allp[0]->getstr();
        update(allp[0]);
        ui->textBrowser->setText(x);
        curplayer=0;

    }
    else if(p2&&(!p1))
    {
        allp[1]->setdirc("w");
        p2=allp[1]->act();
        for(int i=0 ; i<6;i++)
        {
            allm[i]->act();
        }
        if (g->wol(allp[1])==1)
        {
            allp[1]->setdirc("esc");
            p2=allp[1]->act();
            allp[0]->setdirc("");
            allp[1]->setdirc("");
            allp[0]->act();
            allp[1]->act();
            QMessageBox::information(this,"winner","eva is winner");
        }
        else if (g->wol(allp[1])==0)
        {
            allp[1]->setdirc("esc");
            p2=allp[1]->act();
            allp[0]->setdirc("");
            allp[1]->setdirc("");
            allp[0]->act();
            allp[1]->act();
            QMessageBox::information(this,"loser","eva is loser");
        }
        QString x;
        x=allp[1]->getstr();
        update(allp[1]);
        ui->textBrowser->setText(x);
        curplayer=1;
    }
    else if(p1&&p2)
    {
        if(curplayer==0)
        {
            allp[0]->setdirc("w");
            p1=allp[0]->act();
            allp[0]->setdirc("");
            allp[1]->setdirc("");
            allp[0]->act();
            allp[1]->act();
           /* for(int i=0 ; i<6;i++)
            {
                allm[i]->act();
            }*/
            if (g->wol(allp[0])==1)
            {
                allp[0]->setdirc("esc");
                p1=allp[0]->act();
                allp[0]->setdirc("");
            allp[1]->setdirc("");
            allp[0]->act();
            allp[1]->act();
                QMessageBox::information(this,"winner","wonka is winner");
            }
            else if (g->wol(allp[0])==0)
            {
                allp[0]->setdirc("esc");
                p1=allp[0]->act();
                allp[0]->setdirc("");
            allp[1]->setdirc("");
            allp[0]->act();
            allp[1]->act();
                QMessageBox::information(this,"winner","wonka is loser");
            }

            QString x;
            x=allp[1]->getstr();
            update(allp[1]);
            ui->textBrowser->setText(x);
            curplayer=1;
        }
        else if(curplayer==1)
        {
            allp[1]->setdirc("w");
            p2=allp[1]->act();
            allp[0]->setdirc("");
            allp[1]->setdirc("");
            allp[0]->act();
            allp[1]->act();
            for(int i=0 ; i<6;i++)
            {
                allm[i]->act();
            }
            if (g->wol(allp[1])==1)
            {
                allp[1]->setdirc("esc");
                p2=allp[1]->act();
                allp[0]->setdirc("");
            allp[1]->setdirc("");
            allp[0]->act();
            allp[1]->act();
                QMessageBox::information(this,"winner","eva is winner");
            }
            else if (g->wol(allp[1])==0)
            {
                allp[1]->setdirc("esc");
                p2=allp[1]->act();
                allp[0]->setdirc("");
            allp[1]->setdirc("");
            allp[0]->act();
            allp[1]->act();
                QMessageBox::information(this,"loser","eva is loser");
            }
            QString x;
            x=allp[0]->getstr();
            update(allp[0]);
            ui->textBrowser->setText(x);
            curplayer=0;
        }
    }

    else
    { ui->textBrowser->setText("all player out the game please start a new game");
    }

    steps->play();
}

void Form::on_down_clicked() //down
{
    if(p1&&(!p2))
    {
        allp[0]->setdirc("s");
        p1=allp[0]->act();
        for(int i=0 ; i<6;i++)
        {
            allm[i]->act();
        }
        if (g->wol(allp[0])==1)
        {
            allp[0]->setdirc("esc");
            p1=allp[0]->act();
            QMessageBox::information(this,"winner","wonka is winner");
        }
        else if (g->wol(allp[0])==0)
        {
            allp[0]->setdirc("esc");
            p1=allp[0]->act();
            QMessageBox::information(this,"winner","wonka is loser");
        }

        QString x;
        x=allp[0]->getstr();
        update(allp[0]);
        ui->textBrowser->setText(x);
        curplayer=0;

    }
    else if(p2&&(!p1))
    {
        allp[1]->setdirc("s");
        p2=allp[1]->act();
        for(int i=0 ; i<6;i++)
        {
            allm[i]->act();
        }
        if (g->wol(allp[1])==1)
        {
            allp[1]->setdirc("esc");
            p2=allp[1]->act();
            QMessageBox::information(this,"winner","eva is winner");
        }
        else if (g->wol(allp[1])==0)
        {
            allp[1]->setdirc("esc");
            p2=allp[1]->act();
            QMessageBox::information(this,"loser","eva is loser");
        }
        QString x;
        x=allp[1]->getstr();
        update(allp[1]);
        ui->textBrowser->setText(x);
        curplayer=1;
    }
    else if(p1&&p2)
    {
        if(curplayer==0)
        {
            allp[0]->setdirc("s");
            p1=allp[0]->act();
            allp[0]->setdirc("");
            allp[1]->setdirc("");
            allp[0]->act();
            allp[1]->act();
           /* for(int i=0 ; i<6;i++)
            {
                allm[i]->act();
            }*/
            if (g->wol(allp[0])==1)
            {
                allp[0]->setdirc("esc");
                p1=allp[0]->act();
                allp[0]->setdirc("");
                allp[1]->setdirc("");
                allp[0]->act();
                allp[1]->act();
                QMessageBox::information(this,"winner","wonka is winner");
            }
            else if (g->wol(allp[0])==0)
            {
                allp[0]->setdirc("esc");
                p1=allp[0]->act();
                allp[0]->setdirc("");
                allp[1]->setdirc("");
                allp[0]->act();
                allp[1]->act();
                QMessageBox::information(this,"winner","wonka is loser");
            }

            QString x;
            x=allp[1]->getstr();
            update(allp[1]);
            ui->textBrowser->setText(x);
            curplayer=1;
        }
        else if(curplayer==1)
        {
            allp[1]->setdirc("s");
            p2=allp[1]->act();
            allp[0]->setdirc("");
            allp[1]->setdirc("");
            allp[0]->act();
            allp[1]->act();
            for(int i=0 ; i<6;i++)
            {
                allm[i]->act();
            }
            if (g->wol(allp[1])==1)
            {
                allp[1]->setdirc("esc");
                p2=allp[1]->act();
                allp[0]->setdirc("");
            allp[1]->setdirc("");
            allp[0]->act();
            allp[1]->act();
                QMessageBox::information(this,"winner","eva is winner");
            }
            else if (g->wol(allp[1])==0)
            {
                allp[1]->setdirc("esc");
                p2=allp[1]->act();
                allp[0]->setdirc("");
                allp[1]->setdirc("");
                allp[0]->act();
                allp[1]->act();
                QMessageBox::information(this,"loser","eva is loser");
            }
            QString x;
            x=allp[0]->getstr();
            update(allp[0]);
            ui->textBrowser->setText(x);
            curplayer=0;
        }
    }

    else
    { ui->textBrowser->setText("all player out the game please start a new game");
    }

    steps->play();

}

void Form::on_pushButton_8_clicked()  //drop
{

    treasure *t=NULL;
    items * i=NULL;
    fixeditem *f=NULL;
    room *croom;
    QString x ="";
    QString y="";
    x=ui->lineEdit->text();
    ui->lineEdit->setText("");


    if (curplayer==0)
    {

        croom=allp[0]->getcur();
        i=allp[0]->sitem(x);
        t=allp[0]->streasure(x);
        f=allp[0]->sitemfix(x);

        if(i!=NULL)
        {
            allp[0]->drop(i);
            croom->drop(i);
            allp[0]->setdirc("");
            allp[1]->setdirc("");
            allp[0]->act();
            allp[1]->act();
            y=allp[0]->getstr();
            ui->textBrowser->setText(y);

        }
        else if(t!=NULL)
        {
            allp[0]->dropt(t);
            croom->dropt(t);
            allp[0]->setdirc("");
            allp[1]->setdirc("");
            allp[0]->act();
            allp[1]->act();
            y=allp[0]->getstr();
            ui->textBrowser->setText(y);

        }
        else if(f!=NULL)
        {
            allp[0]->dropfix(f);
            croom->dropfix(f);
            allp[0]->setdirc("");
            allp[1]->setdirc("");
            allp[0]->act();
            allp[1]->act();
            y=allp[0]->getstr();
            ui->textBrowser->setText(y);

        }
        if (g->wol(allp[0])==1)
        {
            allp[0]->setdirc("esc");
            p1=allp[0]->act();
            allp[0]->setdirc("");
            allp[1]->setdirc("");
            allp[0]->act();
            allp[1]->act();
            QMessageBox::information(this,"winner","wonka is winner");
        }
        else if (g->wol(allp[0])==0)
        {
            allp[0]->setdirc("esc");
            p1=allp[0]->act();
            allp[0]->setdirc("");
            allp[1]->setdirc("");
            allp[0]->act();
            allp[1]->act();
            QMessageBox::information(this,"winner","wonka is loser");
        }
        update(allp[0]);

    }
    else if (curplayer==1)
    {
        croom=allp[1]->getcur();
        i=allp[1]->sitem(x);
        t=allp[1]->streasure(x);
        f=allp[1]->sitemfix(x);
        if(i!=NULL)
        {
            allp[1]->drop(i);
            croom->drop(i);
            allp[0]->setdirc("");
            allp[1]->setdirc("");
            allp[1]->act();
            allp[0]->act();
            y=allp[1]->getstr();
            ui->textBrowser->setText(y);
        }
        else if(t!=NULL)
        {
            allp[1]->dropt(t);
            croom->dropt(t);
            allp[0]->setdirc("");
            allp[1]->setdirc("");
            allp[1]->act();
            allp[0]->act();
            y=allp[1]->getstr();
            ui->textBrowser->setText(y);
        }
        else if(f!=NULL)
        {
            allp[1]->dropfix(f);
            croom->dropfix(f);
            allp[0]->setdirc("");
            allp[1]->setdirc("");
            allp[0]->act();
            allp[1]->act();
            y=allp[1]->getstr();
            ui->textBrowser->setText(y);

        }
        if (g->wol(allp[1])==1)
        {
            allp[1]->setdirc("esc");
            p2=allp[1]->act();
            allp[0]->setdirc("");
            allp[1]->setdirc("");
            allp[0]->act();
            allp[1]->act();
            QMessageBox::information(this,"winner","eva is winner");
        }
        else if (g->wol(allp[1])==0)
        {
            allp[1]->setdirc("esc");
            p2=allp[1]->act();
            allp[0]->setdirc("");
            allp[1]->setdirc("");
            allp[0]->act();
            allp[1]->act();
            QMessageBox::information(this,"loser","eva is loser");
        }
        update(allp[1]);
    }

}

void Form::on_pushButton_7_clicked()//pick up
{


    treasure *t=NULL;
    items    *i=NULL;
    fixeditem *f=NULL;
    room *croom;
    QString x ="";
    QString y="";
    x=ui->lineEdit->text();
    ui->lineEdit->setText("");
    if (curplayer==0)
    {

        croom=allp[0]->getcur();
        i=croom->sitem(x);
        t=croom->streasure(x);
        f=croom->sitemfix(x);
        if(i!=NULL)
        {
            croom->pickup(i);
            allp[0]->pickup(i);
            allp[0]->setdirc("");
            allp[1]->setdirc("");
            allp[0]->act();
            allp[1]->act();
            y=allp[0]->getstr();
            ui->textBrowser->setText(y);

        }
        else if(t!=NULL)
        {
            croom->pickupt(t);
            allp[0]->pickupt(t);
            allp[0]->setdirc("");
            allp[1]->setdirc("");
            allp[0]->act();
            allp[1]->act();
            y=allp[0]->getstr();
            ui->textBrowser->setText(y);

        }
        else if(f!=NULL)
        {
            croom->pickupfix(f);
            allp[0]->pickupfix(f);
            allp[0]->setdirc("");
            allp[1]->setdirc("");
            allp[0]->act();
            allp[1]->act();
            y=allp[0]->getstr();
            ui->textBrowser->setText(y);

        }
        if (g->wol(allp[0])==1)
        {
            allp[0]->setdirc("esc");
            p1=allp[0]->act();
            allp[0]->setdirc("");
            allp[1]->setdirc("");
            allp[0]->act();
            allp[1]->act();
            QMessageBox::information(this,"winner","wonka is winner");
        }
        else if (g->wol(allp[0])==0)
        {
            allp[0]->setdirc("esc");
            p1=allp[0]->act();
            allp[0]->setdirc("");
            allp[1]->setdirc("");
            allp[0]->act();
            allp[1]->act();
            QMessageBox::information(this,"loser","wonka is loser");
        }
        update(allp[0]);
    }
    else if (curplayer==1)
    {

        croom=allp[1]->getcur();
        i=croom->sitem(x);
        t=croom->streasure(x);
        f=croom->sitemfix(x);
        if(i!=NULL)
        {
            croom->pickup(i);
            allp[1]->pickup(i);
            allp[0]->setdirc("");
            allp[1]->setdirc("");
            allp[1]->act();
            allp[0]->act();
            y=allp[1]->getstr();
            ui->textBrowser->setText(y);

        }
        if(t!=NULL)
        {
            croom->pickupt(t);
            allp[1]->pickupt(t);
            allp[0]->setdirc("");
            allp[1]->setdirc("");
            allp[1]->act();
            allp[0]->act();
            y=allp[1]->getstr();
            ui->textBrowser->setText(y);

        }

        else if(f!=NULL)
        {
            croom->pickupfix(f);
            allp[1]->pickupfix(f);
            allp[0]->setdirc("");
            allp[1]->setdirc("");
            allp[0]->act();
            allp[1]->act();
            y=allp[1]->getstr();
            ui->textBrowser->setText(y);

        }
        if (g->wol(allp[1])==1)
        {
            allp[1]->setdirc("esc");
            p1=allp[1]->act();
            allp[0]->setdirc("");
            allp[1]->setdirc("");
            allp[0]->act();
            allp[1]->act();
            QMessageBox::information(this,"winner","wonka is winner");
        }
        else if (g->wol(allp[1])==false)
        {
            allp[1]->setdirc("esc");
            p1=allp[1]->act();
            allp[0]->setdirc("");
            allp[1]->setdirc("");
            allp[0]->act();
            allp[1]->act();
            QMessageBox::information(this,"loser","eva is loser");
        }
        update(allp[1]);
    }
}

void Form::on_pushButton_4_clicked()
{

}
