#ifndef KERROSTALO_H
#define KERROSTALO_H

#include "kerros.h"
#include "katutaso.h"

using namespace std;

class Kerrostalo
{
public:
    Kerrostalo();

    Katutaso *eka;
    Kerros *toka, *kolmas;

    void maaritaKerrokset();
    double laskeKulutus();
};

#endif // KERROSTALO_H
