#pragma once

#include <QtWidgets/QMainWindow>
#include<QUdpSocket>
#include "ui_vsqtproject.h"

class vsqtproject : public QMainWindow
{
    Q_OBJECT

public:
    vsqtproject(QWidget *parent, QString name);
    //重写关闭事件
    void closeEvent(QCloseEvent*);
    enum Msgtype { Msg, UserEnter, UserLeft };//枚举三种信息，普通信息，用户进入，用户离开
    void sndMsg(Msgtype type);//广播udp信息
    QString getName();//获取名字
    QString getMsg();//获取信息
    void userEnter(QString username);//处理用户进入
    void userLeft(QString username, QString time);//处理用户退出
    void ReceiveMessage();//接受udp信息
    ~vsqtproject();
signals:
    void closeWidget();

private:
    Ui::vsqtprojectClass ui;
    QString myname;
    quint16 port;//端口
    QUdpSocket* udpSocket;
};
