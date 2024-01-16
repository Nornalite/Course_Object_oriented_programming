#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int guesser(int maxNo);

int main()
{
    int maxNo = 0;
    cout << "Anna korkein arvottava luku: ";
    cin >> maxNo;
    int guesses = guesser(maxNo);
    cout << "Tarvitsit " << guesses << " arvausta." << endl;

    return 0;
}

int guesser(int maxNo) {
    time_t currTime;
    srand(time(&currTime));

    int guessNo = 0;
    int randNo = rand() % maxNo + 1;

    int guess = 0;
    bool guessTrue = false;
    while (!guessTrue) {
        cout << "Arvaa luku: ";
        cin >> guess;
        guessNo++;
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

    return guessNo;
}
