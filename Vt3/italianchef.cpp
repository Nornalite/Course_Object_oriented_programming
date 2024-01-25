#include "italianchef.h"

ItalianChef::ItalianChef(string givenName, int recipeWater, int recipeFlour)
{
    name = givenName;
    water = recipeWater;
    flour = recipeFlour;
    cout << "Italialaisen Chef " << name << "n konstruktori" << endl;
}

void ItalianChef::makePasta() {
    cout << "Chef " << name << " kokkaa pastaa." << endl;
    cout << "Kulhoon menee " << water << " desiä vettä ja " << flour << " grammaa jauhoja." << endl << "...shh! Salainen resepti!" << endl;
}

string ItalianChef::getName() {
    return name;
}
