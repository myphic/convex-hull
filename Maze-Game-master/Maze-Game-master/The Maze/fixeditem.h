#ifndef FIXEDITEM_H
#define FIXEDITEM_H
#include "object.h"

class fixeditem : public object
{
public:
    fixeditem(QString n, QString d, int h, int a);
    bool act();
};

#endif // FIXEDITEM_H
