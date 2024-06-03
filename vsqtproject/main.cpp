#include "vsqtproject.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    vsqtproject w;
    w.show();
    return a.exec();
}
