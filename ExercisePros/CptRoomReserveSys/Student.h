#pragma once
#include <iostream>
#include "Identify.h"

using namespace std;

class Student : public Identify
{
public:
	Student();
	Student(int id, string name, string pwd);	// 含参构造函数

	virtual void showMenu();	// 展示用户界面虚函数

	// 申请预约
	void applyOrder();

	// 查看自己的预约
	void showMyOrder();

	// 查看所有预约情况
	void showAllOrder();

	// 取消预约
	void cancelOrder();

public:
	int stuId;	// 学号

};