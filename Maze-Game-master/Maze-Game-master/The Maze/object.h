#ifndef OBJECT_H
#define OBJECT_H
#include <QString>

class object
{
protected:
QString name;
QString disc;
int morehealth;
int moreattak;
public:
   object();
   virtual bool act()=0;
   int geth();
   int geta();
   QString getn();
   QString getd();
};

#endif // OBJECT_H
