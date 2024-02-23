#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qpushbutton.h>


enum Operations {ADD, SUBTRACT, MULTIPLY, DIVIDE, DECIMAL, POWER, ANS, ENTER, ERASE, CLEAR, LEFTBOX, RIGHTBOX};

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // Get called when a button is pressed on the calculator - which one is called depends on which
    // QPushButton array below (numButtons or operationButtons) the clicked button belongs to
    void numberClicked();
    void operationClicked();

private:
    Ui::MainWindow *ui;

    char operand;
    double num1, num2, result;
    bool decimalActiveNum1, decimalActiveNum2;
    signed char decimalPositionNum1, decimalPositionNum2;
    //
    unsigned char activeBox;

    // references to the various buttons on the calculator
    QPushButton *numButtons[10];
    QPushButton *operationButtons[12];

    // Zero out everything
    void ResetCalculator();

    // These output the values of various variables to the screen for maximum calculator action
    void PrintAll();
    void PrintNum1();
    void PrintNum2();
    void PrintResult();

    void PrintOperand();
    void CalculateResult();
    void EraseCharacter();

    // Changes which num textbox takes input at any given time & changes background colours for an extra highlight
    void Num1Active();
    void Num2Active();
};
#endif // MAINWINDOW_H
