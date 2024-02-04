#include "asunto.h"

Asunto::Asunto()
{
    cout << "Asunto luotu." << endl;
}

void Asunto::maarita(int aMaara, int nMaara) {
    asukasMaara = aMaara;
    neliot = nMaara;

    cout << "Asunto maaritetty, asukkaita " << asukasMaara << ", nelioita " << neliot << "." << endl;
}

double Asunto::laskeKulutus() {
    return asukasMaara * neliot;
}
