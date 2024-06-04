#include "login.h"
#include"vsqtproject.h"
login::login(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	//����ͼ��
	this->setWindowIcon(QIcon("bitmap1.bmp"));
	//����ͼ��
	this->setWindowTitle("QtChat 2024");

	QVector<QToolButton*> vector;
	for (int i = 0; i < 9; i++)
	{
		QToolButton* btn = new QToolButton(this);
		//����ͷ��
		btn->setIcon(QPixmap("bitmap1.bmp"));
		//����ͷ���С
		btn->setIconSize(QPixmap("bitmap1.bmp").size());
		//��������
		btn->setText(QString("dkhsvkjd"));
		//ͼƬ����һ����ʾ
		btn->setAutoRaise(true);//����͸��
		btn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
		ui.vlayout->addWidget(btn);
		vector.push_back(btn);
	}
	for (int i = 0; i < 9; i++)
	{
		connect(vector[i], &QToolButton::clicked, [=]() {
			vsqtproject* wider = new vsqtproject(nullptr, vector[i]->text());
			wider->setWindowIcon(vector[i]->icon());
			wider->setWindowTitle(vector[i]->text()); 
			wider->show();
			});
	}
}

login::~login()
{}
