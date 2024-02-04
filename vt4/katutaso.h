#ifndef KATUTASO_H
#define KATUTASO_H

#include "kerros.h"

using namespace std;

class Katutaso : public Kerros
{
public:
    Katutaso();

    void maaritaAsunnot() override;
    double laskeKulutus() override;

private:
    Asunto as1, as2;
};

#endif // KATUTASO_H
