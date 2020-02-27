#include "FileCopierMainWindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FileCopierMainWindow w;
    w.show();
    return a.exec();
}
