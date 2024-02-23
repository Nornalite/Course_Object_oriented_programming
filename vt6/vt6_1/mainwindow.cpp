#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    counter = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_buttonPlusOne_clicked()
{
    counter++;
    ui->labelNumber->setText(QString::number(counter));
}

void MainWindow::on_buttonReset_clicked()
{
    counter = 0;
    ui->labelNumber->setText(QString::number(counter));
}
