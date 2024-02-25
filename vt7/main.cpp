#include "chesstimer.h"

#include <QApplication>

using namespace std;

int main(int argc, char *argv[])
{
    cout << "Printing" << endl;

    QApplication app(argc, argv);
    ChessTimer window;
    window.show();
    return app.exec();
}
