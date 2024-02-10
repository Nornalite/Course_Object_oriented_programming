#include "kerros.h"

Kerros::Kerros()
{
    cout << "Kerros luotu." << endl;
}

void Kerros::maaritaAsunnot() {
    cout << "Kerroksen asuntojen maaritys, tulossa 4 kpl asuntoja." << endl;
    as1 = new Asunto();
    as1->maarita(3, 90);
    as2 = new Asunto();
    as2->maarita(3, 90);
    as3 = new Asunto();
    as3->maarita(3, 90);
    as4 = new Asunto();
    as4->maarita(3, 90);
}

double Kerros::laskeKulutus() {
    double kulutus = as1->laskeKulutus() + as2->laskeKulutus() + as3->laskeKulutus() + as4->laskeKulutus();
    return kulutus;
}

