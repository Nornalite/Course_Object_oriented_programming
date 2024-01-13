#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void guesser(int maxNo);

int main()
{
    int maxNo = 0;
    cout << "Anna korkein arvottava luku: ";
    cin >> maxNo;
    guesser(maxNo);

    return 0;
}

void guesser(int maxNo) {
    time_t currTime;
    srand(time(&currTime));

    int randNo = rand() % maxNo + 1;

    int guess = 0;
    bool guessTrue = false;
    while (!guessTrue) {
        cout << "Arvaa luku: ";
        cin >> guess;

        if (guess == randNo) {
            cout << "Arvasit oikein!" << endl;
            guessTrue = true;
        }
        else if (guess < randNo) {
            cout << "Antamasi luku on liian pieni." << endl;
        }
        else {
            cout << "Antamasi luku on liian suuri." << endl;
        }
    }
}
