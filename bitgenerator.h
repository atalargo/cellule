#ifndef BITGENERATOR_H
#define BITGENERATOR_H

#include "datagenerator.h"
#include <QBitArray>

class BitGenerator : public DataGenerator
{
public:
    BitGenerator();

    void init(short int nb_rows);
    void refresh();
    void getData();

protected:
    QBitArray bits;

    short int getPos(short int x, short int y) { return (x*_nb_rows) + y;}

};

#endif // BITGENERATOR_H
