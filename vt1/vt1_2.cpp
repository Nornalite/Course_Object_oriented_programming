#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void guesser();

int main()
{
    guesser();

    return 0;
}

void guesser() {
    time_t currtime;
    srand(time(&currtime));

    int randno = rand() % 19 + 1;

    int guess = 0;
    bool guessTrue = false;
    while (!guessTrue) {
        cout << "Arvaa luku: ";
        cin >> guess;

        if (guess == randno) {
            cout << "Arvasit oikein!" << endl;
            guessTrue = true;
        }
        else if (guess < randno) {
            cout << "Antamasi luku on liian pieni." << endl;
        }
        else {
            cout << "Antamasi luku on liian suuri." << endl;
        }
    }
}

