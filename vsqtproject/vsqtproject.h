#pragma once

#include <QtWidgets/QMainWindow>
#include<QUdpSocket>
#include "ui_vsqtproject.h"

class vsqtproject : public QMainWindow
{
    Q_OBJECT

public:
    vsqtproject(QWidget *parent, QString name);
    //��д�ر��¼�
    void closeEvent(QCloseEvent*);
    enum Msgtype { Msg, UserEnter, UserLeft };//ö��������Ϣ����ͨ��Ϣ���û����룬�û��뿪
    void sndMsg(Msgtype type);//�㲥udp��Ϣ
    QString getName();//��ȡ����
    QString getMsg();//��ȡ��Ϣ
    void userEnter(QString username);//�����û�����
    void userLeft(QString username, QString time);//�����û��˳�
    void ReceiveMessage();//����udp��Ϣ
    ~vsqtproject();
signals:
    void closeWidget();

private:
    Ui::vsqtprojectClass ui;
    QString myname;
    quint16 port;//�˿�
    QUdpSocket* udpSocket;
};
