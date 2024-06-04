#include "vsqtproject.h"

vsqtproject::vsqtproject(QWidget* parent, QString name)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    myname = name;
    this->port = 80;
    this->udpSocket = new QUdpSocket(this);
    udpSocket->bind(port, QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint);
    //绑定端口
    //采用shareAddress模式(即允许其他的服务器连接到相同的地址和端口)
    //特别是用在多客户端监听同一服务器端口等时特别有效），还有ReuseAddressHint模式(重新连接服务器)
    //监听信号
}

QString vsqtproject::getName()
{
    return this->myname;
}

QString vsqtproject::getMsg()
{
    QString msg = ui.msgTxtEdit->toHtml();//返回输入框的内容
    ui.msgTxtEdit->clear();//将内容清空
    ui.msgTxtEdit->setFocus();//设置光标
    return msg;
}

void vsqtproject::sndMsg(vsqtproject::Msgtype type)
{
    QByteArray array;
    QDataStream stream(&array, QIODevice::WriteOnly);

    stream << type << this->getName();//流入类型和用户名称

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
    //书写报文
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
