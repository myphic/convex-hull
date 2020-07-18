#ifndef ITEMS_H
#define ITEMS_H
#include "object.h"

class items : public object
{
public:
    items(QString n,QString d ,int h,int a);
    bool act();
};

#endif // ITEMS_H
