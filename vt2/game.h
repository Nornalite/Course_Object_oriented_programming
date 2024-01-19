#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/* A guessing game: for the first round you have to try to guess which random number between 1 and 10 the game has
 * picked. For subsequent rounds you can pick the maximum number yourself. The game tells you whether your guess is too
 * high or low (or correct) and keeps track of the possible range of values (e.g. between 14 and 75) for a bit of QoL.
*/
class Game
{
public:
    Game(int);
    ~Game();
    void play();
private:
    int maxNumber;
    int randomNumber;
    int playerGuess;
    int numOfGuesses;
    int lowBand, highBand;

    void resetGame();
    void askMaxNum();
    int takeGuess();
    void printGameResult();
};

#endif // GAME_H
