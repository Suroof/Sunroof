<<<<<<< HEAD
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
=======
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
>>>>>>> f8f427154cd2cb28f912abfce2b95a1a3b0fc219
