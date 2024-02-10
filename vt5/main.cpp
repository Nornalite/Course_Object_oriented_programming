#include <iostream>
#include "kerrostalo.h"

using namespace std;

int main()
{
    Kerrostalo *pKerrostalo = new Kerrostalo();
    pKerrostalo->maaritaKerrokset();
    cout << "Kerrostalon kulutus " << pKerrostalo->laskeKulutus() << "." << endl;
    delete pKerrostalo;
    return 0;
}
