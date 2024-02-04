#include <iostream>
#include "kerrostalo.h"

using namespace std;

int main()
{
    Kerrostalo kTalo;
    kTalo.maaritaKerrokset();
    cout << "Kerrostalon kulutus " << kTalo.laskeKulutus() << "." << endl;
    return 0;
}
