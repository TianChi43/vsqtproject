#include "login.h"
#include"vsqtproject.h"
login::login(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	//设置图标
	this->setWindowIcon(QIcon("bitmap1.bmp"));
	//设置图标
	this->setWindowTitle("QtChat 2024");

	QVector<QToolButton*> vector;
	for (int i = 0; i < 9; i++)
	{
		QToolButton* btn = new QToolButton(this);
		//设置头像
		btn->setIcon(QPixmap("bitmap1.bmp"));
		//设置头像大小
		btn->setIconSize(QPixmap("bitmap1.bmp").size());
		//设置网名
		btn->setText(QString("dkhsvkjd"));
		//图片文字一块显示
		btn->setAutoRaise(true);//设置透明
		btn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
		ui.vlayout->addWidget(btn);
		vector.push_back(btn);
		IsShow.push_back(false);//代表窗口还没打开
	}
	for (int i = 0; i < 9; i++)
	{
		connect(vector[i], &QToolButton::clicked, [=]() {
			if (IsShow[i])
			{
				QMessageBox::warning(this, "Warning", "It has been opened");
				return;
			}
			IsShow[i] = true;
			vsqtproject* wider = new vsqtproject(nullptr, vector[i]->text());
			wider->setWindowIcon(vector[i]->icon());
			wider->setWindowTitle(vector[i]->text()); 
			wider->show();
			//关闭时将对应的isshow变为false;
			connect(wider, &vsqtproject::closeWidget, this, [=]() {
				IsShow[i] = false;
				});
			});
	}
}

login::~login()
{}
