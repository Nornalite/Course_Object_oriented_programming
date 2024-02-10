#ifndef ASUNTO_H
#define ASUNTO_H

#include <iostream>

using namespace std;

class Asunto
{
public:
    Asunto();

    int asukasMaara;
    int neliot;

    void maarita(int, int);
    double laskeKulutus();
};

#endif // ASUNTO_H
