#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qpushbutton.h>

enum Operations {ADD, SUBTRACT, MULTIPLY, DIVIDE, DECIMAL, POWER, ANS, ENTER, ERASE, CLEAR, LEFTNO, RIGHTNO, LEFTBOX, RIGHTBOX};

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
    void numberClicked();
    void operationClicked();

private:
    Ui::MainWindow *ui;

    char operand;
    float num1, num2, result;
    bool decimalActiveNum1, decimalActiveNum2;
    signed char decimalPositionNum1, decimalPositionNum2;
    signed char cursorPositionNum1, cursorPositionNum2;
    unsigned char activeBox;

    QPushButton *numButtons[10];
    QPushButton *operationButtons[14];

    void PrintAll();
    void PrintNum1();
    void PrintNum2();
    void PrintResult();
    void PrintOperand();

    void Num1Active();
    void Num2Active();
};
#endif // MAINWINDOW_H
