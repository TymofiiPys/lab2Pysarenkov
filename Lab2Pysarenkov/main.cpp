#include "mainwindow.h"
#include "algstruct.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    remove("struct.txt");
    remove("steps.txt");
    remove("temp.txt");
    QApplication a(argc, argv);
    MainWindow w;
    AlgStruct ast;
    w.show();
    const int ai= a.exec();
    remove("struct.txt");
    return ai;
}
