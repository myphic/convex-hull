#ifndef TREASURE_H
#define TREASURE_H
#include <iostream>
#include <QString>
#include <vector>

class treasure
{
public:
    treasure(QString n);
    QString getname();
private:
    QString name;

};

#endif // TREASURE_H
