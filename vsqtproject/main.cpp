#include "vsqtproject.h"
#include <QtWidgets/QApplication>
#include"login.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    vsqtproject w;
    w.show();
    //login b;
    //b.show();
    return a.exec();
}
