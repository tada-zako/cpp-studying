#include "Teacher.h"

Teacher::Teacher()
{}

Teacher::Teacher(int id, string name, string pwd)
{
	this->teaId = id;
	this->userName = name;
	this->userPwd = pwd;
}

void Teacher::showMenu()	// 展示用户界面虚函数
{

}

// 查看所有预约
void Teacher::showAllOrder()
{

}

// 审核预约
void Teacher::verifyOrder()
{

}

// 退出登录
void Teacher::logOff()
{

}
