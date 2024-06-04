#include "vsqtproject.h"

vsqtproject::vsqtproject(QWidget* parent, QString name)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    myname = name;
    this->port = 80;
    this->udpSocket = new QUdpSocket(this);
    udpSocket->bind(port, QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint);
    //�󶨶˿�
    //����shareAddressģʽ(�����������ķ��������ӵ���ͬ�ĵ�ַ�Ͷ˿�)
    //�ر������ڶ�ͻ��˼���ͬһ�������˿ڵ�ʱ�ر���Ч��������ReuseAddressHintģʽ(�������ӷ�����)
    //�����ź�
}

QString vsqtproject::getName()
{
    return this->myname;
}

QString vsqtproject::getMsg()
{
    QString msg = ui.msgTxtEdit->toHtml();//��������������
    ui.msgTxtEdit->clear();//���������
    ui.msgTxtEdit->setFocus();//���ù��
    return msg;
}

void vsqtproject::sndMsg(vsqtproject::Msgtype type)
{
    QByteArray array;
    QDataStream stream(&array, QIODevice::WriteOnly);

    stream << type << this->getName();//�������ͺ��û�����

    switch (type) {
    case Msg:
        if (ui.msgTxtEdit->toPlainText() == "")
        {
            QMessageBox::warning(this, "warnging", "Your send information is empty");
            return;
        }
        stream << this->getMsg();
        break;
    case UserEnter:
        break;
    case UserLeft:
        break;
    }
    //��д����
    udpSocket->writeDatagram(array.data(), array.size(), QHostAddress::Broadcast, this->port);
}

void vsqtproject::ReceiveMessage()
{

}

void vsqtproject::closeEvent(QCloseEvent*)
{
    emit this->closeWidget();
}

vsqtproject::~vsqtproject()
{}
