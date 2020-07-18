#ifndef WIDGET_H
#define WIDGET_H
#include <vector>
#include <QWidget>
//#include "form.h"
#include "agent.h"
#include "player.h"
#include "monster.h"
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void addallp(vector<player *> x);
    void addallm(vector<monster *> x);
    bool p1=true;
    bool p11=true;
    bool p2=true;
    QString path;
    void run();
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
    vector <player * > allp;
    vector <monster * > allm;

};

#endif // WIDGET_H
