#include "chef.h"

Chef::Chef() {
    //
}

Chef::Chef(string givenName)
{
    name = givenName;
    cout << "Chef " << name << ":n konstruktori" << endl;
}


Chef::~Chef()
{
    cout << "Chef " << name << ":n destruktori" << endl;
}

void Chef::makeSalad() {
    cout << "Chef " << name << " valmistaa salaattia." << endl;
}

void Chef::makeSoup() {
    cout << "Chef " << name << " keittää keittoa." << endl;
}
