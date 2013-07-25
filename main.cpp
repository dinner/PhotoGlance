#include "mainwindow.h"
#include <QApplication>
#include <QStyleFactory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//  QApplication::setStyle(QStyleFactory::create("GTK"));
    MainWindow w;
    w.Init();
    w.CreateMenu();
    w.show();
    return a.exec();
}
