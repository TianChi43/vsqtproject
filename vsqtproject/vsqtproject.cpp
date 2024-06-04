#include "vsqtproject.h"

vsqtproject::vsqtproject(QWidget* parent, QString name)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    myname = name;
}

vsqtproject::~vsqtproject()
{}
