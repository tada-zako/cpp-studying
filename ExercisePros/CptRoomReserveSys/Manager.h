#pragma once
#include <iostream>
#include "Identify.h"
#include "Teacher.h"
#include "Student.h"

using namespace std;

class Manager :public Identify
{
public:
	Manager();
	Manager(string name, string pwd);

	virtual void showMenu();	// 展示用户界面虚函数

	// 查看账号
	void showAllUser();

	// 添加账号
	void addUser();

	// 查看机房信息
	void showCptRoom();

	// 清空所有预约记录
	void cleanOrder();

	// 初始化存储容器
	void initVec();

	// 初始化机房信息
	void initCrVec();

	// 检测是否发生id号重复
	bool checkIdRepeat(int id, int type);


public:
	vector<Student> stuVec;		// 存储所有学生账户对象
	vector<Teacher> teaVec;		// 存储所有教师账户对象

	vector<ComputerRoom> crVec;		// 存储所有机房信息
};