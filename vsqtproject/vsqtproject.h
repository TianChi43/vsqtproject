#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_vsqtproject.h"

class vsqtproject : public QMainWindow
{
    Q_OBJECT

public:
    vsqtproject(QWidget *parent, QString name);
    //重写关闭事件
    void closeEvent(QCloseEvent*);
    ~vsqtproject();
signals:
    void closeWidget();


private:
    Ui::vsqtprojectClass ui;
    QString myname;
};
