#ifndef CHESSTIMER_H
#define CHESSTIMER_H

#include <QMainWindow>
#include <QTimer>
#include <iostream>
#include <qlabel.h>
#include <qprogressbar.h>
#include <qpushbutton.h>

QT_BEGIN_NAMESPACE
namespace Ui { class ChessTimer; }
QT_END_NAMESPACE

class ChessTimer : public QMainWindow
{
    Q_OBJECT

public:
    ChessTimer(QWidget *parent = nullptr);
    ~ChessTimer();

private slots:
    void TimerTriggered();

    void on_buttonStart_clicked();
    void on_buttonStop_clicked();
    void on_button120Sec_clicked();
    void on_button5Min_clicked();
    void on_buttonP1_clicked();
    void on_buttonP2_clicked();

private:
    struct Player {
        QLabel *nameLabel;
        QProgressBar *progressBar;
        QPushButton *turnButton;

        int timeTotal, timeRemaining, barProgress;

        void SetupPlayer(QLabel *label, QProgressBar *bar, int time) {
            nameLabel = label;
            progressBar = bar;
            timeTotal = time;
            timeRemaining = time;
            progressBar->setValue(0);
        };
        void SetupGame(int time) {
            timeTotal = time;
            timeRemaining = time;
            UpdateTimeRemaining(0);
        };
        int CheckGameState(int timeSinceLastUpdate) {
            UpdateTimeRemaining(timeSinceLastUpdate);
            return GetTimeRemaining();
        };
        void UpdateTimeRemaining(int tick) {
            timeRemaining = timeRemaining - tick;
            barProgress = ((float)timeRemaining / (float)timeTotal) * 100;
            progressBar->setValue(barProgress);
        };
        void UpdateProgressBar(int value) {
            progressBar->setValue(value);
        };
        int GetTimeRemaining() {
            return timeRemaining;
        };
        void TurnOver() {

        }
    };

    Ui::ChessTimer *ui;
    QTimer *timer;
    Player players[2];

    short activePlayer;
    int maxTime, tickDuration;

    void StartGame();
    void ResetGame();
    void StartTimer();
    void CheckTimer();
    void SwitchPlayers(short PressedButton);
    void GameOver();
    void UpdateCentralLabel(QString text);
};


#endif // CHESSTIMER_H
