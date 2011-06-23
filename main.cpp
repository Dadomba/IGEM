#include <QtGui/QApplication>
#include "mainwindow.h"
#include "manager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Manager m(&w);
    w.show();

    return a.exec();
}
