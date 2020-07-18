#include "widget.h"
#include "ui_widget.h"
#include <qmessagebox.h>
#include <QString>
#include"form.h"
#include <QtGui>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);


}
void Widget::run()
{
QImage image(path+"Horror-wallpapers-19.jpg");
int h=this->height();
int w=this->width();
QImage image2 = image.scaled(w*2.5,h*2.5, Qt::KeepAspectRatio);

    QPalette* palette = new QPalette();
    QBrush y=*(new QBrush(QPixmap::fromImage(image2)));
    palette->setBrush(QPalette::Background,y);
    setPalette(*palette);
    QPixmap pix(path+"palace.png");
    ui->label->setPixmap(pix);
}
Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_2_clicked()
{
    QMessageBox::StandardButton reply;
    reply=QMessageBox::question(this,"Quit","do you really wanna leave ?!!! it is too scary out there..",QMessageBox::Yes|QMessageBox::No);
    if (reply==QMessageBox::Yes)
    {
            this->close();
    }

}
void Widget::addallp(vector<player *> x)
{
allp=x;
}
void Widget::addallm(vector<monster *> x)
{
allm=x;
}
void Widget::on_pushButton_clicked()
{
    Form *a=new Form[1];
    a->addallp(allp);
    a->addallm(allm);
    a-> p1=p1;
    a-> p11=p11;
    a->p2=p2;
    a->path=path;
    a->run();
    a->showFullScreen();
    (a->mainwindow)=this;

    ui->pushButton->setText("continue");
    this->hide();
}
