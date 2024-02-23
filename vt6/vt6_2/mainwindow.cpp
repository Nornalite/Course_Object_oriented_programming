#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Assigning number buttons to the numButtons[] array & connection to the numberClicked() slot
    for (unsigned int i = 0; i < sizeof(numButtons) / sizeof(numButtons[0]); i++) {
        QString name = "button" + QString::number(i);
        //qDebug() << "Trying to assign " << name;
        QPushButton *button = findChild<QPushButton*>(name);
        numButtons[i] = button;
        QObject::connect(numButtons[i], SIGNAL(clicked(bool)), this, SLOT(numberClicked()));
    }

    // Assigning operation buttons to their array
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
    operationButtons[LEFTBOX] = ui->buttonLeftBox;
    operationButtons[RIGHTBOX] = ui->buttonRightBox;
    // & conecting them to the operationClicked() slot
    for (unsigned int i = 0; i < sizeof(operationButtons) / sizeof(operationButtons[0]); i++) {
        QObject::connect(operationButtons[i], SIGNAL(clicked(bool)), this, SLOT(operationClicked()));
    }

    // Colour changes to the boxes displaying numbers & operands
    ui->num1->setStyleSheet("QLabel { background-color: lightgray; }");
    ui->num2->setStyleSheet("QLabel { background-color: lightgray; }");
    ui->operation->setStyleSheet("QLabel { background-color: lightgray; }");
    ui->result->setStyleSheet("QLabel { background-color: lightgray; }");

    // Initialization to 0
    ResetCalculator();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::numberClicked()
{
    // Each number button's name ends in said button's number;
    // it's extracted and used for further input
    QString buttonNoString = sender()->objectName().last(1);
    char buttonNoChar = buttonNoString[0].toLatin1();

    // Create pointers to the active box
    // Honestly two if-elses would've been the sensible choice
    double *pNum = (activeBox == LEFTBOX) ? &num1 : &num2;
    signed char *pDecPos = (activeBox == LEFTBOX) ? &decimalPositionNum1 : &decimalPositionNum2;
    bool *pDecActive = (activeBox == LEFTBOX) ? &decimalActiveNum1 : &decimalActiveNum2;
    void (MainWindow::*fPointer)() = (activeBox == LEFTBOX) ? &MainWindow::PrintNum1 : &MainWindow::PrintNum2;

    // For numbers with a decimal, add a fraction corresponding to the pressed key
    // (e.g. 17.2 + 0.03 -> 17.23) and increase the decimal location accordingly
    if (*pDecActive) {
        *pDecPos = *pDecPos + 1;
        *pNum = *pNum + ((buttonNoChar - 48) / pow(10, *pDecPos));
    }
    // For plain ints multiply previous number by 10 and add the new digit
    // (e.g 72 -> 720 + 3 -> 723)
    else {
        *pNum = *pNum * 10 + (buttonNoChar - 48);
    }

    (this->*fPointer)();
}

void MainWindow::operationClicked()
{
    // Figure out which button sent the signal through comparison of addresses
    QPushButton *senderObj = qobject_cast<QPushButton*>(sender());
    unsigned char operation = sizeof(operationButtons) / sizeof(operationButtons[0]) + 1;
    for (unsigned int i = 0; i < sizeof(operationButtons) / sizeof(operationButtons[0]); i++) {
        if (senderObj == operationButtons[i]) {
            operation = i;
        }
    }

    // Doctor's found, time to operate
    switch (operation) {
    // These five operands all affect the same box
    case ADD:
    case SUBTRACT:
    case MULTIPLY:
    case DIVIDE:
    case POWER:
        Num2Active();
        operand = operation;
        PrintOperand();
        break;
    case DECIMAL:
        // Adds a decimal to the active box
        decimalActiveNum1 = (activeBox == LEFTBOX) ? true : false;
        decimalActiveNum2 = (activeBox == RIGHTBOX) ? true : false;
        PrintNum1();
        PrintNum2();
        break;
    case ANS:
        // Places the current result in the active box
        num1 = (activeBox == LEFTBOX) ? result : num1;
        num2 = (activeBox == RIGHTBOX) ? result : num2;
        PrintNum1();
        PrintNum2();
        break;
    case ENTER:
        // Execute calculation
        CalculateResult();
        break;
    case ERASE:
        EraseCharacter();
        break;
    case CLEAR:
        ResetCalculator();
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

void MainWindow::ResetCalculator()
{
    num1 = 0;
    num2 = 0;
    result = 0;
    operand = ' ';

    decimalPositionNum1 = 0;
    decimalPositionNum2 = 0;
    decimalActiveNum1 = false;
    decimalActiveNum2 = false;

    PrintAll();
    Num1Active();
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
    // Add a decimal character to the number in "X." situations
    if (decimalActiveNum1 && decimalPositionNum1 == 0) {
        ui->num1->setText(ui->num1->text() + '.');
    }
}

void MainWindow::PrintNum2()
{
    ui->num2->setText(QString::number(num2, 'f', decimalPositionNum2));
    // Add a decimal character to the number in "X." situations
    if (decimalActiveNum2 && decimalPositionNum2 == 0) {
        ui->num2->setText(ui->num2->text() + '.');
    }
}

void MainWindow::PrintResult()
{
    // The result comes with as many decimals as are in the most precise number found
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

void MainWindow::CalculateResult()
{
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
}

void MainWindow::EraseCharacter()
{
    // Pointers to the active box
    // Honestly two if-elses would've been the sensible choice
    double *pNum = (activeBox == LEFTBOX) ? &num1 : &num2;
    signed char *pDecPos = (activeBox == LEFTBOX) ? &decimalPositionNum1 : &decimalPositionNum2;
    bool *pDecActive = (activeBox == LEFTBOX) ? &decimalActiveNum1 : &decimalActiveNum2;
    void (MainWindow::*fPointer)() = (activeBox == LEFTBOX) ? &MainWindow::PrintNum1 : &MainWindow::PrintNum2;


    if (*pDecActive && *pDecPos == 0) {
        *pDecActive = false;
    }
    else if (!*pDecActive) {
        *pNum = (int)(*pNum) / 10;
    }
    else {
        char multiplier = pow(10, *pDecPos - 1);
        *pNum = ((double)((unsigned long int)(*pNum * multiplier))) / multiplier;
        *pDecPos = *pDecPos - 1;
    }
    (this->*fPointer)();
}

void MainWindow::Num1Active()
{
    activeBox = LEFTBOX;
    ui->num1->setStyleSheet("QLabel { background-color: whitesmoke; }");
    ui->num2->setStyleSheet("QLabel { background-color: lightgray; }");
}

void MainWindow::Num2Active()
{
    activeBox = RIGHTBOX;
    ui->num1->setStyleSheet("QLabel { background-color: lightgray; }");
    ui->num2->setStyleSheet("QLabel { background-color: whitesmoke; }");
}
