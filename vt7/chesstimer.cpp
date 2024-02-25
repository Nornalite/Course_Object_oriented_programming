#include "chesstimer.h"
#include "ui_chesstimer.h"

ChessTimer::ChessTimer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ChessTimer)
{
    ui->setupUi(this);

    players[0].SetupPlayer(ui->labelP1, ui->pBarP1, 0);
    players[1].SetupPlayer(ui->labelP2, ui->pBarP2, 0);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(TimerTriggered()));

    ResetGame();

    UpdateCentralLabel("Choose Game Length And Press Start");
}

ChessTimer::~ChessTimer()
{
    delete ui;
}

void ChessTimer::StartGame()
{
    UpdateCentralLabel("The Game Is On!");
    players[0].SetupGame(maxTime);
    players[1].SetupGame(maxTime);
    tickDuration = maxTime / 100;
    timer->start(tickDuration);
}

void ChessTimer::SwitchPlayers(short pressedButton)
{
    if (pressedButton != activePlayer) return;

    // Stop timer, take note of its progress
    timer->stop();
    int timeOnTimer = timer->remainingTime();
    players[activePlayer].CheckGameState(timeOnTimer);

    // Switch to next player
    activePlayer = (activePlayer == 1) ? 0 : 1;
    // Set up timer
    int nextPlayerGameTime = players[activePlayer].GetTimeRemaining();
    tickDuration = (nextPlayerGameTime < tickDuration) ? nextPlayerGameTime : maxTime / 100;
    timer->start(tickDuration);
}

void ChessTimer::ResetGame()
{
    activePlayer = 0;
    maxTime = 0;
    tickDuration = maxTime / 100;
    players[0].SetupGame(maxTime);
    players[1].SetupGame(maxTime);
}

void ChessTimer::GameOver()
{
    timer->stop();

    QString lossText = "Game over, player ";
    lossText.append((char)(activePlayer + 49));
    lossText.append(" lost!");
    UpdateCentralLabel(lossText);

    ResetGame();
}

void ChessTimer::UpdateCentralLabel(QString text)
{
    ui->label->setText(text);
}

void ChessTimer::TimerTriggered()
{
    int timeLeft = players[activePlayer].CheckGameState(tickDuration);
    if (timeLeft <= 0) {
        GameOver();
    }
    else if (timeLeft < tickDuration) {
        tickDuration = timeLeft;
        timer->start(tickDuration);
    }
}


void ChessTimer::on_buttonStart_clicked()
{
    if (maxTime < 1) {
        UpdateCentralLabel("Select Game Duration");
        return;
    }
    StartGame();
}

void ChessTimer::on_buttonStop_clicked()
{
    timer->stop();
    ResetGame();
    players[0].UpdateProgressBar(0);
    players[1].UpdateProgressBar(0);
    UpdateCentralLabel("Game Stopped");
}

void ChessTimer::on_button120Sec_clicked()
{
    maxTime = 120000;
    players[0].SetupGame(maxTime);
    players[1].SetupGame(maxTime);
    UpdateCentralLabel("Press Start");
}

void ChessTimer::on_button5Min_clicked()
{
    maxTime = 300000;
    players[0].SetupGame(maxTime);
    players[1].SetupGame(maxTime);
    UpdateCentralLabel("Press Start");
}

void ChessTimer::on_buttonP1_clicked()
{
    SwitchPlayers(0);
}

void ChessTimer::on_buttonP2_clicked()
{
    SwitchPlayers(1);
}

