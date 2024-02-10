#include "kerrostalo.h"

Kerrostalo::Kerrostalo()
{
    cout << "Kerrostalo luotu." << endl;
}

void Kerrostalo::maaritaKerrokset() {
    cout << "Kerrostalon kerrokset maarityksessa." << endl;
    eka = new Katutaso();
    eka->maaritaAsunnot();
    toka = new Kerros();
    toka->maaritaAsunnot();
    kolmas = new Kerros();
    kolmas->maaritaAsunnot();
}

double Kerrostalo::laskeKulutus() {
    double kulutus = eka->laskeKulutus() + toka->laskeKulutus() + kolmas->laskeKulutus();
    return kulutus;
}
