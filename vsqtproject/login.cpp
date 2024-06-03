#include "login.h"

login::login(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	//设置图标
	this->setWindowIcon(QIcon("bitmap1.bmp"));
	//设置图标
	this->setWindowTitle("QtChat 2024");
}

login::~login()
{}
