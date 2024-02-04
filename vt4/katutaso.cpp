#include "katutaso.h"

Katutaso::Katutaso()
{
    cout << "Katutaso luotu." << endl;
}

void Katutaso::maaritaAsunnot() {
    cout << "Katutason asuntoja maarityksessa 2 kpl." << endl;
    as1.maarita(3, 90);
    as2.maarita(3, 90);
}

double Katutaso::laskeKulutus() {
    double kulutus = as1.laskeKulutus() + as2.laskeKulutus();
    return kulutus;
}
