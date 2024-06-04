#include "vsqtproject.h"

vsqtproject::vsqtproject(QWidget* parent, QString name)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    myname = name;
}

void vsqtproject::closeEvent(QCloseEvent*)
{
    emit this->closeWidget();
}

vsqtproject::~vsqtproject()
{}
