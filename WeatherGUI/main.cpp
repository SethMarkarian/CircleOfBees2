#include "mainwindow.h"
#include "weatherwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WeatherWidget ww(nullptr);
    ww.show();
    /*MainWindow w;
    w.show();*/

    return a.exec();
}
