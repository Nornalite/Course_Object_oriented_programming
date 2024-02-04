#ifndef KATUTASO_H
#define KATUTASO_H

#include "kerros.h"

using namespace std;

class Katutaso : public Kerros
{
public:
    Katutaso();

    Asunto as1, as2;

    void maaritaAsunnot() override;
    double laskeKulutus() override;
};

#endif // KATUTASO_H
