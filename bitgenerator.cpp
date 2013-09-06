#include "bitgenerator.h"

#include <QTime>

#include <QDebug>

BitGenerator::BitGenerator()
{
}

void BitGenerator::init(short int nb_rows)
{
    _nb_rows = nb_rows;
    bits.clear();

    bits.resize(nb_rows*nb_rows);

    short int x =0;
    short int y = 0;
    for(x = 0; x < nb_rows; x++)
    {
        for(y = 0; y < nb_rows; y++)
        {
            if (qrand() % 2 == 1)
                bits.setBit(getPos(x,y), 1);
        }
    }
}

void BitGenerator::refresh()
{
    QBitArray calcBit(_nb_rows*_nb_rows, 0);

    int rowmax = _nb_rows-1;
    QTime t1;t1.start();
//    QThread thread1;

    int base;
    int nbLive;
    int jp1;int jm1;int ip1; int im1;

    for(int i = 1;i < _nb_rows-1;i++)
    {
        for(int j = 1;j<_nb_rows-1;j++)
        {
            base = getPos(i,j);
            nbLive = 0;

            jp1 = j+1;
            jm1 = j-1;
            ip1 = i+1;
            im1 = i-1;

//            nbLive = bits.testBit(getPos(im1,jm1)) +
//                    bits.testBit(getPos(im1,j)) +
//                    bits.testBit(getPos(im1,jp1)) +
//                    bits.testBit(getPos(i,jm1)) +
//                    bits.testBit(getPos(i,jp1)) +
//                    bits.testBit(getPos(ip1,jm1)) +
//                    bits.testBit(getPos(ip1,j)) +
//                    bits.testBit(getPos(ip1,jp1));

//            calcBit.clearBit(base);
//            if (nbLive == 3 || (nbLive == 2 && bits.testBit(base)))
//                calcBit.setBit(base);

            if (j < rowmax)
            {
                if (bits.testBit(getPos(i,jp1)))
                    nbLive++;
                if (i > 0 && bits.testBit(getPos(im1, jp1)))
                    nbLive++;
                if (i < rowmax && bits.testBit(getPos(ip1, jp1)))
                    nbLive++;
            }
            if (j > 0 )
            {
                if(bits.testBit(getPos(i,jm1)))
                    nbLive++;
                if (i > 0 && bits.testBit(getPos(im1, jm1)))
                    nbLive++;
                if (i < rowmax && bits.testBit(getPos(ip1, jm1)))
                    nbLive++;
            }
            if (i < rowmax && bits.testBit(getPos(ip1,j)))
                nbLive++;
            if (i > 0 && bits.testBit(getPos(im1, j)))
                nbLive++;

            if(bits.testBit(base) == 1 && (nbLive == 2 || nbLive == 3))
                calcBit.setBit(base);
            else if (bits.testBit(base) == 0 && nbLive == 3)
                calcBit.setBit(base);

        }
    }
    qDebug() << "Cycle for " << t1.elapsed() << " ms";
    bits = calcBit;
}

void BitGenerator::getData()
{

}
