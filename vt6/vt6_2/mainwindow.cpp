#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for (unsigned int i = 0; i < sizeof(numButtons) / sizeof(numButtons[0]); i++) {
        QString name = "button" + QString::number(i);
        //qDebug() << "Trying to assign " << name;
        QPushButton *button = findChild<QPushButton*>(name);
        numButtons[i] = button;
        QObject::connect(numButtons[i], SIGNAL(clicked(bool)), this, SLOT(numberClicked()));
    }

    operationButtons[ADD] = ui->buttonAdd;
    operationButtons[SUBTRACT] = ui->buttonSubtract;
    operationButtons[MULTIPLY] = ui->buttonMultiply;
    operationButtons[DIVIDE] = ui->buttonDivide;
    operationButtons[DECIMAL] = ui->buttonDecimal;
    operationButtons[POWER] = ui->buttonPower;
    operationButtons[ANS] = ui->buttonAns;
    operationButtons[ENTER] = ui->buttonEnter;
    operationButtons[ERASE] = ui->buttonErase;
    operationButtons[CLEAR] = ui->buttonClear;
    operationButtons[LEFTNO] = ui->buttonLeftInBox;
    operationButtons[RIGHTNO] = ui->buttonRightInBox;
    operationButtons[LEFTBOX] = ui->buttonLeftOnCalc;
    operationButtons[RIGHTBOX] = ui->buttonRightOnCalc;

    //qDebug() << "MainWindow initialization step 2";

    for (unsigned int i = 0; i < sizeof(operationButtons) / sizeof(operationButtons[0]); i++) {
        QObject::connect(operationButtons[i], SIGNAL(clicked(bool)), this, SLOT(operationClicked()));
    }

    ui->num1->setStyleSheet("QLabel { background-color: lightgray; color: black; }");
    ui->num2->setStyleSheet("QLabel { background-color: lightgray; color: black; }");
    ui->operation->setStyleSheet("QLabel { background-color: lightgray; color: black; }");
    ui->result->setStyleSheet("QLabel { background-color: lightgray; color: black; }");

    activeBox = LEFTBOX;

    num1 = 0;
    num2 = 0;
    result = 0;
    operand = ' ';

    decimalActiveNum1 = false;
    decimalActiveNum2 = false;
    decimalPositionNum1 = 0;
    decimalPositionNum2 = 0;
    cursorPositionNum1 = 0;
    cursorPositionNum2 = 0;

    PrintAll();
    Num1Active();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::numberClicked()
{
    QString buttonNoString = sender()->objectName().last(1);
    char buttonNoChar = buttonNoString[0].toLatin1();

    if (activeBox == LEFTBOX) {
        if ((cursorPositionNum1 < decimalPositionNum1) || (decimalActiveNum1 && (cursorPositionNum1 <= decimalPositionNum1))) {
            decimalPositionNum1++;
            num1 = num1 + ((buttonNoChar - 48) / pow(10, decimalPositionNum1));
        }
        else {
            num1 = num1 * 10 + (buttonNoChar - 48);
        }

    }
    else if (activeBox == RIGHTBOX) {
        if ((cursorPositionNum2 < decimalPositionNum2) || (decimalActiveNum2 && (cursorPositionNum2 <= decimalPositionNum2))) {
            decimalPositionNum2++;
            num2 = num2 + ((buttonNoChar - 48) / pow(10, decimalPositionNum2));
        }
        else {
            num2 = num2 * 10 + (buttonNoChar - 48);
        }
    }

    PrintNum1();
    PrintNum2();
}

void MainWindow::operationClicked()
{
    QPushButton *senderObj = qobject_cast<QPushButton*>(sender());
    unsigned char operation = sizeof(operationButtons) / sizeof(operationButtons[0]) + 1;

    for (unsigned int i = 0; i < sizeof(operationButtons) / sizeof(operationButtons[0]); i++) {
        //qDebug() << senderObj;
        //qDebug() << operationButtons[i];
        if (senderObj == operationButtons[i]) {
            operation = i;
        }
    }

    switch (operation) {
    case ADD:
    case SUBTRACT:
    case MULTIPLY:
    case DIVIDE:
    case POWER:
        operand = operation;
        PrintOperand();
        break;
    case DECIMAL:
        decimalActiveNum1 = (activeBox == LEFTBOX) ? true : false;
        decimalActiveNum2 = (activeBox == RIGHTBOX) ? true : false;
        PrintNum1();
        PrintNum2();
        break;
    case ANS:
        num1 = (activeBox == LEFTBOX) ? result : num1;
        num2 = (activeBox == RIGHTBOX) ? result : num2;
        PrintNum1();
        PrintNum2();
        break;
    case ENTER:
        switch (operand) {
        case ADD:
            result = num1 + num2;
            break;
        case SUBTRACT:
            result = num1 - num2;
            break;
        case MULTIPLY:
            result = num1 * num2;
            break;
        case DIVIDE:
            result = (num2 != 0) ? (num1 / num2) : 0;
            break;
        case POWER:
            result = pow((double)num1, (double)num2);
            break;
        default:
            break;
        }
        PrintResult();
        break;
    case ERASE:
        if (activeBox == LEFTBOX) {
            if (decimalActiveNum1 && cursorPositionNum1 < decimalPositionNum1) {

            }
            else {

            }
        }
        num2 = (activeBox == RIGHTBOX) ? (num2 / 10) : num2;
        PrintNum1();
        PrintNum2();
        break;
    case CLEAR:
        num1 = 0;
        num2 = 0;
        result = 0;
        decimalPositionNum1 = 0;
        decimalPositionNum2 = 0;
        decimalActiveNum1 = false;
        decimalActiveNum2 = false;
        PrintAll();
        break;
    case LEFTNO:
        decimalPositionNum1 = (activeBox == LEFTBOX) ? decimalPositionNum1 - 1 : decimalPositionNum1;
        decimalPositionNum2 = (activeBox == RIGHTBOX) ? decimalPositionNum2 - 1 : decimalPositionNum2;
        break;
    case RIGHTNO:
        decimalPositionNum1 = (activeBox == LEFTBOX) ? decimalPositionNum1 + 1 : decimalPositionNum1;
        decimalPositionNum2 = (activeBox == RIGHTBOX) ? decimalPositionNum2 + 1 : decimalPositionNum2;
        break;
    case LEFTBOX:
        Num1Active();
        break;
    case RIGHTBOX:
        Num2Active();
        break;
    default:
        break;
    }
}

void MainWindow::PrintAll()
{
    PrintNum1();
    PrintNum2();
    PrintResult();
    PrintOperand();
}

void MainWindow::PrintNum1()
{
    ui->num1->setText(QString::number(num1, 'f', decimalPositionNum1));
    if (decimalActiveNum1 && decimalPositionNum1 == 0) {
        ui->num1->setText(ui->num1->text() + '.');
    }
}

void MainWindow::PrintNum2()
{
    ui->num2->setText(QString::number(num2, 'f', decimalPositionNum2));
    if (decimalActiveNum2 && decimalPositionNum2 == 0) {
        ui->num2->setText(ui->num2->text() + '.');
    }
}

void MainWindow::PrintResult()
{
    char decimalNo = (decimalPositionNum1 > decimalPositionNum2) ? decimalPositionNum1 : decimalPositionNum2;
    ui->result->setText(QString::number(result, 'f', decimalNo));
}

void MainWindow::PrintOperand()
{
    char op;
    switch (operand) {
    case ADD:
        op = '+';
        break;
    case SUBTRACT:
        op = '-';
        break;
    case MULTIPLY:
        op = '*';
        break;
    case DIVIDE:
        op = '/';
        break;
    case POWER:
        op = '^';
        break;
    default:
        op = ' ';
        break;
    }

    ui->operation->setText(QString::fromLatin1(&op, 1));
}

void MainWindow::Num1Active()
{
    activeBox = LEFTBOX;
    ui->num1->setStyleSheet("QLabel { background-color: whitesmoke; color: black; }");
    ui->num2->setStyleSheet("QLabel { background-color: lightgray; color: black; }");
}

void MainWindow::Num2Active()
{
    activeBox = RIGHTBOX;
    ui->num1->setStyleSheet("QLabel { background-color: lightgray; color: black; }");
    ui->num2->setStyleSheet("QLabel { background-color: whitesmoke; color: black; }");
}
