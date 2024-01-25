#ifndef CHEF_H
#define CHEF_H

#include <iostream>

using namespace std;

class Chef
{
public:
    Chef();
    Chef(string);
    ~Chef();
    void makeSalad();
    void makeSoup();
protected:
    string name;
};

#endif // CHEF_H
