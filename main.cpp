#include <QApplication>
#include <QDebug>
#include "mainform.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainForm window;
    window.show();

    return app.exec();
}
