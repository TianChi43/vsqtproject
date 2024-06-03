#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_vsqtproject.h"

class vsqtproject : public QMainWindow
{
    Q_OBJECT

public:
    vsqtproject(QWidget *parent = nullptr);
    ~vsqtproject();

private:
    Ui::vsqtprojectClass ui;
};
