/* 重温C++练习——机房预约系统 */
#include <iostream>
#include <fstream>

#include "Global.h"
#include "Identify.h"
#include "Student.h"
#include "Teacher.h"
#include "Manager.h"

using namespace std;


// 登录前处理函数
void login(string filePath, int select);

// 学生登录后函数
void studentMenu(Identify* &student);

// 教师登录后函数
void teacherMenu(Identify* &teacher);

// 管理员登录后函数
void managerMenu(Identify* &manager);

int main(){

	int select = 0;		// 记录输入的选择

	// 进入循环
	while (true) {

		// 打印系统界面
		cout << "\t\t#################### 欢迎使用机房预约系统 ####################" << endl;
		cout << endl;
		cout << "\t\t      **************************************************" << endl;
		cout << "\t\t      ********* +---------------------------+ **********" << endl;
		cout << "\t\t      ********* |       请确认您的身份：    | **********" << endl;
		cout << "\t\t      ********* |                           | **********" << endl;
		cout << "\t\t      ********* |                           | **********" << endl;
		cout << "\t\t      ********* |        1、 学  生         | **********" << endl;
		cout << "\t\t      ********* |                           | **********" << endl;
		cout << "\t\t      ********* |        2、 教  师         | **********" << endl;
		cout << "\t\t      ********* |                           | **********" << endl;
		cout << "\t\t      ********* |        3、 管理员         | **********" << endl;
		cout << "\t\t      ********* |                           | **********" << endl;
		cout << "\t\t      ********* |        0、 退  出         | **********" << endl;
		cout << "\t\t      ********* |                           | **********" << endl;
		cout << "\t\t      ********* |                           | **********" << endl;
		cout << "\t\t      ********* +---------------------------+ **********" << endl;
		cout << "\t\t      **************************************************" << endl;
		cout << "\t\t      **************************************************" << endl;

		cout << endl;
		cout << "###请输入您的选择：" << endl;

		cin >> select;

		switch (select)
		{
		case 1:
			// 学生身份登入
			login(STUDENT_FILE, 1);
			break;

		case 2:
			// 教师身份登入
			login(TEACHER_FILE, 2);
			break;

		case 3:
			// 管理员身份登入
			login(ADMIN_FILE, 3);
			break;
		
		case 0:
			cout << "###期待您下次使用" << endl;
			system("pause");
			return 0;
			break;

		default:
			cerr << "!!!输入有误，请重新输入" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	
}

// 登录前处理函数
void login(string filePath, int select)
{
	// 打开信息文件
	ifstream ifs;
	ifs.open(filePath, ios::in);

	// 判断文件是否打开
	if (!ifs.is_open()) {
		// 文件打开失败
		cerr << "!!!文件打开失败" << endl;
		system("pause");
		system("cls");
		return;
	}

	// 多态身份指针
	Identify* identify = NULL;

	// 判断选择的身份，并验证身份
	int id = 0;
	string name;
	string pwd;

	if (select == 1) {
		cout << "请输入您的学号：" << endl;
		cin >> id;
	}
	else if (select == 2) {
		cout << "请输入您的教师号：" << endl;
		cin >> id;
	}

	cout << "请输入用户名：" << endl;
	cin >> name;

	cout << "请输入密码：" << endl;
	cin >> pwd;

	if (select == 1) {
		// 读入文件信息
		int fId = 0;
		string fName;
		string fPwd;

		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "###学生登录成功" << endl;
				system("pause");
				system("cls");

				identify = new Student(id, name, pwd);
				// 打开学生界面
				studentMenu(identify);
				ifs.close();	// 关闭文件流
				return;
			}
		}
	}
	else if (select == 2) {
		// 读入文件信息
		int fId = 0;
		string fName;
		string fPwd;

		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {

			if (fId == id && fName == name && fPwd == pwd) {
				cout << "###教师登录成功" << endl;
				system("pause");
				system("cls");

				identify = new Teacher(id, name, pwd);
				// 打开教师界面

				ifs.close();	// 关闭文件流
				return;
			}
		}
	}
	else if (select == 3) {
		// 读入文件信息
		int fId = 0;
		string fName;
		string fPwd;

		while (ifs >> fName && ifs >> fPwd) {

			if (fName == name && fPwd == pwd) {
				cout << "###管理员登录成功" << endl;
				system("pause");
				system("cls");

				identify = new Manager(name, pwd);
				// 打开管理员界面
				managerMenu(identify);
				ifs.close();	// 关闭文件流
				return;
			}
		}
	}

	// 身份验证失败
	cerr << "!!!用户身份验证失败" << endl;
	ifs.close();	// 关闭文件流

	system("pause");
	system("cls");
	return;
}

// 学生登录后函数
void studentMenu(Identify*& student)
{
	// 指针转换类型，使可以调用子类独有函数
	Student* stu = (Student*)student;

	while (true) {
		// 调用菜单函数
		stu->showMenu();

		// 接受指令，并作出反应
		int command = 0;	// 存储指令

		cin >> command;

		switch (command)
		{
		case 1:
			// 申请预约
			stu->applyOrder();
			break;

		case 2:
			// 查看自己的预约
			stu->showMyOrder();
			break;

		case 3:
			// 查看所有预约情况
			stu->showAllOrder();
			break;

		case 4:
			// 取消预约
			stu->cancelOrder();
			break;

		case 0:
			// 退出登录
			cout << "###退出登录成功" << endl;
			system("pause");
			system("cls");
			return;

		default:
			// 输入错误
			cerr << "!!!输入有误，请重新输入" << endl;
			system("pause");
			system("cls");
		}
	}
}

// 管理员登录后函数
void managerMenu(Identify* &manager)
{
	// 指针转换类型，使可以调用子类独有函数
	Manager* man = (Manager*)manager;

	while (true) {
		// 调用菜单函数
		man->showMenu();

		// 接受指令，并作出反应
		int command = 0;	// 存储指令

		cin >> command;

		switch (command)
		{
		case 1:
			// 查看账号
			man->showAllUser();
			break;

		case 2:
			// 添加账号
			man->addUser();
			break;

		case 3:
			// 查看机房信息
			man->showCptRoom();
			break;

		case 4:
			// 清空所有预约记录
			man->cleanOrder();
			break;

		case 0:
			// 退出登录
			cout << "###退出登录成功" << endl;
			system("pause");
			system("cls");
			return;

		default:
			// 输入错误
			cerr << "!!!输入有误，请重新输入" << endl;
			system("pause");
			system("cls");
		}
	}

}
