#pragma once
#include <iostream>
#include "Identify.h"

using namespace std;

class Teacher :public Identify
{
public:
	Teacher();
	Teacher(int id, string name, string pwd);

	virtual void showMenu();	// 展示用户界面虚函数

	// 查看所有预约
	void showAllOrder();

	// 审核预约
	void verifyOrder();

	// 退出登录
	void logOff();


public:
	int teaId;		// 教师号

};