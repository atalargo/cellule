#ifndef DATAGENERATOR_H
#define DATAGENERATOR_H

class DataGenerator
{
public:
    DataGenerator();

    virtual void init(short int nb_rows) = 0;

    virtual void refresh() = 0;

    virtual void getData() = 0;

protected:
    short int _nb_rows;

};

#endif // DATAGENERATOR_H
