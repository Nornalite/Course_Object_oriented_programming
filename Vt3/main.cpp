#include <iostream>
#include "chef.h"
#include "italianchef.h"

using namespace std;

int main()
{
    Chef chef1("Jouko");
    chef1.makeSalad();
    chef1.makeSoup();

    ItalianChef chef2("Michele Massari", 3, 500);
    chef2.makePasta();

    return 0;
}
