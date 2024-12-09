#include "Manager.h"

Manager::Manager()
{}

Manager::Manager(string name, string pwd)
{
	// 初始化管理员数据
	this->userName = name;
	this->userPwd = pwd;

	// 初始化用户容器
	this->initVec();

	// 初始化机房信息
	this->initCrVec();
}

void Manager::showMenu()	// 展示用户界面虚函数
{
	// 打印系统界面
	cout << "\t\t    #################### 欢迎" << this->userName << "登录 ####################" << endl;
	cout << endl;
	cout << "\t\t      **************************************************" << endl;
	cout << "\t\t      ********* +---------------------------+ **********" << endl;
	cout << "\t\t      ********* |       请确认您的操作：    | **********" << endl;
	cout << "\t\t      ********* |                           | **********" << endl;
	cout << "\t\t      ********* |                           | **********" << endl;
	cout << "\t\t      ********* |       1、 查看账号        | **********" << endl;
	cout << "\t\t      ********* |                           | **********" << endl;
	cout << "\t\t      ********* |       2、 添加账号        | **********" << endl;
	cout << "\t\t      ********* |                           | **********" << endl;
	cout << "\t\t      ********* |      3、查看机房信息      | **********" << endl;
	cout << "\t\t      ********* |                           | **********" << endl;
	cout << "\t\t      ********* |      4、清空预约记录      | **********" << endl;
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

// 查看账号
void Manager::showAllUser()
{
	cout << "###系统内学生账户如下：" << endl;

	// 遍历容器，打印所有用户数据
	for (const auto& stu : this->stuVec) {
		cout << "\t学号：" << stu.stuId << "  用户名：" << stu.userName << "  密码：" << stu.userPwd << endl;
	}
	cout << endl;
	cout << "###系统内教师账户如下：" << endl;

	for (const auto& tea : this->teaVec) {
		cout << "\t职工号：" << tea.teaId << "  用户名：" << tea.userName << "  密码：" << tea.userPwd << endl;
	}
	cout << endl;
	cout << "###系统内账号如上" << endl;
	system("pause");
	system("cls");
	return;
}

// 添加账号
void Manager::addUser()
{
	// 提示添加账号类型
	cout << "###请选择添加账号类型" << endl;
	cout << "### 1、学生账号" << endl;
	cout << "### 2、教师账号" << endl;
	cout << "### 0、取消" << endl;
	
	int select = 0;		// 记录选择
	cin >> select;

	int id = 0;
	string name;
	string pwd;
	ofstream ofs;

	while (true) {
		if (select == 1) {
			// 打开学生信息文件
			ofs.open(STUDENT_FILE, ios::app);

			while (true) {
				// 添加学生账户
				cout << "请输入学号：" << endl;
				cin >> id;

				// 检测id重复
				if (this->checkIdRepeat(id, 1)) {
					cerr << "!!!学号重复，请重新输入" << endl;
					continue;
				}
				break;
			}
			
			break;
		}
		else if (select == 2) {
			// 打开教师信息文件
			ofs.open(TEACHER_FILE, ios::app);

			while (true) {
				// 添加学生账户
				cout << "请输入职工号：" << endl;
				cin >> id;

				// 检测id重复
				if (this->checkIdRepeat(id, 2)) {
					cerr << "!!!职工号重复，请重新输入" << endl;
					continue;
				}
				break;
			}

			break;
		}
		else if (select == 0) {
			// 取消
			cout << "###取消操作" << endl;
			system("pause");
			system("cls");
			return;
		}
		else {
			// 错误输入
			cerr << "!!!输入有误，请重新输入" << endl;
			system("pause");
			system("cls");
		}
	}

	cout << "请输入用户名：" << endl;
	cin >> name;

	cout << "请输入密码：" << endl;
	cin >> pwd;

	// 向文件中写入信息
	ofs << id << " " << name << " " << pwd << endl;

	// 提示成功，关闭文件流，重新加载容器
	cout << "###添加用户成功" << endl;
	ofs.close();

	this->initVec();
	system("pause");
	system("cls");

	return;
}

// 查看机房信息
void Manager::showCptRoom() {
	cout << "###机房信息如下：" << endl;

	// 遍历容器，打印所有用户数据
	for (const auto& cr : this->crVec) {
		cout << "\t机房号：" << cr.crId << "  机房容量：" << cr.crCapacity  << "  机房预约状态：" << (cr.statusCode == 1 ? "预约中" : "空闲") << endl;
	}
	cout << endl;
	cout << "###机房信息如上" << endl;
	system("pause");
	system("cls");
	return;
}

// 清空所有预约记录
void Manager::cleanOrder() {

	// 确认是否清空
	cout << "###请确认是否清空所有预约记录" << endl;
	cout << "###1、确认清空" << endl;
	cout << "###2、取消操作" << endl;

	int command = 0;	// 记录操作选项
	cin >> command;

	if (command == 1) {
		// 清空方式打开预约记录文件
		ofstream ofs;
		ofs.open(ORDER_FILE, ios::trunc);

		// 判断打开操作是否成功
		if (!ofs.is_open()) {
			cerr << "!!!清空失败，请重新操作" << endl;
		}
		else {
			cout << "###清空成功" << endl;

			// 重置机房信息状态
			for (auto& cr : this->crVec) {
				cr.statusCode = 0;
			}
			// 反向写入文件
			ofstream crOfs;
			crOfs.open(COMPUTER_FILE, ios::trunc);

			for (const auto& cr : this->crVec) {
				crOfs << cr.crId << " " << cr.crCapacity << " " << cr.statusCode << endl;
			}

			crOfs.close();
		}

		ofs.close();

		system("pause");
		system("cls");
		return;
	}
	
	cout << "###操作取消成功" << endl;
	system("pause");
	system("cls");
}

// 初始化容器
void Manager::initVec()
{
	// 打开用户文件
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);

	// 判断打开是否成功
	if (!ifs.is_open()) {
		cerr << "!!!文件打开失败" << endl;
		system("pause");
		system("cls");
		return;
	}

	// 清空原数据
	this->stuVec.clear();
	this->teaVec.clear();

	// 读取文件流，初始化vec容器
	int fId;
	string fName;
	string fPwd;

	while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
		//cout << fId << " " << fName << " " << fPwd << endl;
		// 添加实例对象
		this->stuVec.push_back(Student(fId, fName, fPwd));
	}

	cout << "当前学生用户数：" << this->stuVec.size() << endl;// 输出测试语句

	ifs.close();

	// 初始化教师容器
	ifs.open(TEACHER_FILE, ios::in);
	// 判断打开是否成功
	if (!ifs.is_open()) {
		cerr << "!!!文件打开失败" << endl;
		system("pause");
		system("cls");
		return;
	}

	while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
		// 添加实例对象
		this->teaVec.push_back(Teacher(fId, fName, fPwd));
	}
	cout << "当前教师用户数：" << this->teaVec.size() << endl;// 输出测试语句
}

// 初始化机房信息
void Manager::initCrVec()
{
	// 打开用户文件
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	// 判断打开是否成功
	if (!ifs.is_open()) {
		cerr << "!!!文件打开失败" << endl;
		system("pause");
		system("cls");
		return;
	}

	// 清空原数据
	this->crVec.clear();

	// 读入机房信息
	ComputerRoom cr;
	while (ifs >> cr.crId && ifs >> cr.crCapacity && ifs >> cr.statusCode) {
		this->crVec.push_back(cr);
	}

	ifs.close();
}

// 检测是否发生id号重复
bool Manager::checkIdRepeat(int id, int type)
{
	if (type == 1) {
		// 检查学号重复
		// 遍历容器，查看是否id重复
		for (const auto& stu : this->stuVec) {
			if (stu.stuId == id) {
				return true;
			}
		}
	}
	else {
		// 检查职工号重复
		for (const auto& tea : this->teaVec) {
			if (tea.teaId == id) {
				return true;
			}
		}
	}

	return false;
}
