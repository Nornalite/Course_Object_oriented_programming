#include "kerrostalo.h"

Kerrostalo::Kerrostalo()
{
    cout << "Kerrostalo luotu." << endl;
}

void Kerrostalo::maaritaKerrokset() {
    cout << "Kerrostalon kerrokset maarityksessa." << endl;
    eka.maaritaAsunnot();
    toka.maaritaAsunnot();
    kolmas.maaritaAsunnot();
}

double Kerrostalo::laskeKulutus() {
    double kulutus = eka.laskeKulutus() + toka.laskeKulutus() + kolmas.laskeKulutus();
    return kulutus;
}
