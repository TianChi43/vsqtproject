#include "login.h"

login::login(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	//����ͼ��
	this->setWindowIcon(QIcon("bitmap1.bmp"));
	//����ͼ��
	this->setWindowTitle("QtChat 2024");
}

login::~login()
{}
