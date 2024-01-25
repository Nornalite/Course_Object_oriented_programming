#ifndef ITALIANCHEF_H
#define ITALIANCHEF_H

#include "chef.h"
#include <iostream>

using namespace std;

class ItalianChef: public Chef
{
public:
    ItalianChef(string, int, int);
    string getName();
    void makePasta();
private:
    int water, flour;
};

#endif // ITALIANCHEF_H
