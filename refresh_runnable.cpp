#include "refresh_runnable.h"

void BitRefreshRunnable30AllDirection::run() {
    int x = _start;
    int y = 0;
    int pos = 0;

    int nbLive = 0;
    int xp1;int xm1;int yp1; int ym1;

    int rowmax = _nb_rows-1;
//        qDebug() << QString("Begin loop original %1 output %2").arg(_bits->size()).arg(_output_bits->size());

    for (;y < _nb_rows; y++)
    {
        for(x = _start;x < _nb_rows; x += _num_thread_pool)
        {
            pos = calcPos(x,y);
//                qDebug() << QString("Loop x: %1 y: %2 ==> %3").arg(x).arg(y).arg(pos);
            nbLive = 0;

            yp1 = y+1;
            ym1 = y-1;
            xp1 = x+1;
            xm1 = x-1;
//                qDebug() << QString("x %1 yp1 %2 cpos %3").arg(x).arg(yp1).arg(calcPos(x, yp1));

            if (y < rowmax)
            {
                if (_bits->testBit(calcPos(x,yp1)))
                    nbLive++;
                if (x > 0 && _bits->testBit(calcPos(xm1, yp1)))
                    nbLive++;
                if (x < rowmax && _bits->testBit(calcPos(xp1, yp1)))
                    nbLive++;
            }

            if (y > 0 )
            {
                if(_bits->testBit(calcPos(x,ym1)))
                    nbLive++;
                if (x > 0 && _bits->testBit(calcPos(xm1, ym1)))
                    nbLive++;
                if (x < rowmax && _bits->testBit(calcPos(xp1, ym1)))
                    nbLive++;
            }

            if (x < rowmax && _bits->testBit(calcPos(xp1,y)))
                nbLive++;

            if (x > 0 && _bits->testBit(calcPos(xm1, y)))
                nbLive++;

//                qDebug() << QString("NB LIVE %1").arg(nbLive);

            if(_bits->testBit(pos) == 1 && (nbLive == 2 || nbLive == 3))
                _output_bits->setBit(pos);
            else if (_bits->testBit(pos) == 0 && nbLive == 3)
                _output_bits->setBit(pos);
//                qDebug("ok boucle");
        }
    }
}

void BitRefreshRunnable110::run() {
    int x = _start;
    int y = 0;
    int pos = 0;

//    int nbLive = 0;
    int xp1;int xm1;//int yp1; int ym1;

    int rowmax = _nb_rows-1;
//        qDebug() << QString("Begin loop original %1 output %2").arg(_bits->size()).arg(_output_bits->size());

    for (;y < _nb_rows; y++)
    {
        for(x = _start;x < _nb_rows; x += _num_thread_pool)
        {
            pos = calcPos(x,y);
//                qDebug() << QString("Loop x: %1 y: %2 ==> %3").arg(x).arg(y).arg(pos);
//            nbLive = 0;

//            yp1 = y+1;
//            ym1 = y-1;
            xp1 = x+1;
            xm1 = x-1;

            bool current = _bits->testBit(pos);
            if (current)
            {
                if (xm1 >= 0 && !_bits->testBit(calcPos(xm1, y)))
                {
                    _output_bits->setBit(pos);
                }
            }
            else
            {
                if ((xm1 < 0  || !_bits->testBit(calcPos(xm1, y))) && (x < rowmax && _bits->testBit(calcPos(xp1, y))))
                    _output_bits->setBit(pos);
                else if ( (xm1 >= 0 && _bits->testBit(calcPos(xm1, y))) && (xp1 >= rowmax || !_bits->testBit(calcPos(xp1, y))))
                        _output_bits->setBit(pos);

            }

        }
    }
}

