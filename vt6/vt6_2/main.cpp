#include "mainwindow.h"

#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    std::cout << "Step 1" << std::endl;
    MainWindow window;
    std::cout << "Step 2" << std::endl;
    window.show();
    std::cout << "Step 3" << std::endl;
    return app.exec();
}
