#ifndef REFRESH_RUNNABLE_H
#define REFRESH_RUNNABLE_H

#include <QRunnable>

#include <QBitArray>

#include <QDebug>

class RefreshRunnable : public QRunnable
{
public:
    RefreshRunnable(int start_value = 0, int num_thread_pool = 1, int nb_rows = 0, QBitArray *original_bits = 0, QBitArray *output_bits = 0) : QRunnable(),
        _start(start_value), _num_thread_pool(num_thread_pool), _nb_rows(nb_rows), _bits(original_bits), _output_bits(output_bits)
    {
        qDebug() << QString("OK runnable %1").arg(_start);
    }

protected:
    int _start;
    int _num_thread_pool;
    int _nb_rows;
    QBitArray *_bits;
    QBitArray *_output_bits;

    int calcPos(int x, int y)
    {
        return (y*_nb_rows)+x;
    }
};


class BitRefreshRunnable30AllDirection : public RefreshRunnable
{
//    Q_OBJECT

public:
    BitRefreshRunnable30AllDirection(int start_value = 0, int num_thread_pool = 1, int nb_rows = 0, QBitArray *original_bits = 0, QBitArray *output_bits = 0) :
        RefreshRunnable(start_value, num_thread_pool, nb_rows, original_bits, output_bits)
    {

    }

protected:
    void run();


};

class BitRefreshRunnable110 : public RefreshRunnable
{
//    Q_OBJECT

public:
    BitRefreshRunnable110(int start_value = 0, int num_thread_pool = 1, int nb_rows = 0, QBitArray *original_bits = 0, QBitArray *output_bits = 0) :
        RefreshRunnable(start_value, num_thread_pool, nb_rows, original_bits, output_bits)
    {

    }

protected:
    void run();


};

#endif // REFRESH_RUNNABLE_H
