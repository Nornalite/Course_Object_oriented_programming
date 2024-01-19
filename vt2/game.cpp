#include "game.h"

/* A guessing game: for the first round you have to try to guess which random number between 1 and 10 the game has
 * picked. For subsequent rounds you can pick the maximum number yourself. The game tells you whether your guess is too
 * high or low (or correct) and keeps track of the possible range of values (e.g. between 14 and 75) for a bit of QoL.
*/

// round 1 is between 1 and 10
Game::Game(int maxGuess)
{
    cout << "Tervetuloa Salmela-Rakennus Oy:lle! Uudessa virassasi vastaat rakennusprojektien hintaneuvotteluista." <<
        endl << "Firma on kiinnostunut kaupungin uuusimpaan rakennusprjektiin osallistumisesta. ";

    maxNumber = maxGuess;

    resetGame();
}

Game::~Game()
{
    cout << endl << "Voi ei, YT-neuvottelut!" << endl << "Valitettavasti olit ainoa palkollinen ilman perhesidoksia johtajiin."
         << endl;
}

/* Resets no of guesses & bands, randomises the number to guess (based on exiting max number) and lets the player know the max number
 */
void Game::resetGame()
{
    numOfGuesses = 0;
    lowBand = 1;
    highBand = maxNumber;

    time_t currTime;
    srand(time(&currTime));
    randomNumber = (rand() % maxNumber) + 1;

    cout << "Kaupungin budjetissa on korkeintaan " << maxNumber << " milj. euroa." << endl;
}

/* Takes player input to set the max number
 */
void Game::askMaxNum()
{
    cout << endl << "Firma on kiinnostunut kaupungin uusimpaan rakennusprojektiin osallistumisesta. "
            "Kuinka suuri rakennusviraston kyseisen vuoden budjetti on? (milj.euroa): " << endl;
    int maxGuess;
    cin >> maxGuess;
    maxNumber = maxGuess;
}

/* Gives the player a range of possible values & takes input, increments no of guesses
 */
int Game::takeGuess()
{
    cout << endl << "Tarjousalue on " << lowBand << "-" << highBand << " milj. euroa. Ammattimaisen hatustavetoanalyysin perusteella "
        "uskot optimaalisen tarjouksen olevan (milj. euroa): ";

    int guess;
    cin >> guess;
    numOfGuesses++;

    return guess;
}

/* Announces success and randomises a bonus value for extra flavour
 */
void Game::printGameResult()
{
    int bonus = rand() % 72 + 30;
    cout << "Onneksi olkoon, " << numOfGuesses << " kuukauden puurtamisen ansiosta sait kiskottua firmalle suurimmat "
        "mahdolliset voitot! Saavutuksesi on ansainnut sinulle " << bonus << " euron bonuksen." << endl;
}

/* Outer loop starts a new game if the player answers Y (or y) to a new game prompt after a correct guess.
 * Inner loop keeps prompting the player to take a guess until a correct one is entered
 */
void Game::play()
{
    bool keepPlaying = true;
    do
    {
        int guess = 0;
        bool guessedRight = false;
        do
        {
            guess = takeGuess();

            if (guess == randomNumber) {
                guessedRight = true;
                printGameResult();
            }
            else if (guess < randomNumber) {
                cout << "Tarjoukseesi vastattiin liiankin nopeasti. Haistat rahan ja valehtelet tarjouksen olleen vahinko." << endl;
                if (guess > lowBand) {
                    lowBand = guess;
                }
            }
            else {
                cout << "Kukaan ei edes vastannut tarjoukseesi. Taisit vaatia liikaa." << endl;
                if (guess < highBand) {
                    highBand = guess;
                }
            }
        }
        while (!guessedRight);

        cout << "Haluatko aloittaa uuden projektin? (Y/N): ";
        char ans;
        cin >> ans;
        if (toupper(ans) == 'Y') {
            keepPlaying = true;
            askMaxNum();
            resetGame();
        }
        else {
            keepPlaying = false;
        }
    }
    while (keepPlaying == true);
}
