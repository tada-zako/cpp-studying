#include "Student.h"

Student::Student()
{}

Student::Student(int id, string name, string pwd)	// 含参构造函数
{
	this->stuId = id;
	this->userName = name;
	this->userPwd = pwd;

}

void Student::showMenu()	// 展示用户界面虚函数
{
	// 打印系统界面
	cout << "\t\t    #################### 欢迎" << this->userName << "登录 ####################" << endl;
	cout << endl;
	cout << "\t\t      **************************************************" << endl;
	cout << "\t\t      ********* +---------------------------+ **********" << endl;
	cout << "\t\t      ********* |       请确认您的操作：    | **********" << endl;
	cout << "\t\t      ********* |                           | **********" << endl;
	cout << "\t\t      ********* |                           | **********" << endl;
	cout << "\t\t      ********* |       1、 申请预约        | **********" << endl;
	cout << "\t\t      ********* |                           | **********" << endl;
	cout << "\t\t      ********* |      2、查看自身预约      | **********" << endl;
	cout << "\t\t      ********* |                           | **********" << endl;
	cout << "\t\t      ********* |      3、查看所有预约      | **********" << endl;
	cout << "\t\t      ********* |                           | **********" << endl;
	cout << "\t\t      ********* |       4、 取消预约        | **********" << endl;
	cout << "\t\t      ********* |                           | **********" << endl;
	cout << "\t\t      ********* |        0、 退  出         | **********" << endl;
	cout << "\t\t      ********* |                           | **********" << endl;
	cout << "\t\t      ********* |                           | **********" << endl;
	cout << "\t\t      ********* +---------------------------+ **********" << endl;
	cout << "\t\t      **************************************************" << endl;
	cout << "\t\t      **************************************************" << endl;

	cout << endl;
	cout << "###请输入您的选择：" << endl;
}

// 申请预约
void Student::applyOrder()
{

}

// 查看自己的预约
void Student::showMyOrder()
{

}

// 查看所有预约情况
void Student::showAllOrder()
{

}

// 取消预约
void Student::cancelOrder()
{

}
