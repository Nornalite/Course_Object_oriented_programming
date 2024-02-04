#ifndef KERROS_H
#define KERROS_H

#include "asunto.h"
using namespace std;

class Kerros
{
public:
    Kerros();

    Asunto as1, as2, as3, as4;

    virtual void maaritaAsunnot();
    virtual double laskeKulutus();
};

#endif // KERROS_H
