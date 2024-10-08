#include "mainwindow.h"
#include <QFile>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyleSheet(":style/style.qss");

    QFile styleFile(":\\style\\style.qss");
    MainWindow w;
    w.show();
    return a.exec();
}
