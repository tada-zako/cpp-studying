/* ����C++��ϰ��������ԤԼϵͳ */
#include <iostream>
#include <fstream>

#include "Global.h"
#include "Identify.h"
#include "Student.h"
#include "Teacher.h"
#include "Manager.h"

using namespace std;


// ��¼ǰ������
void login(string filePath, int select);

// ѧ����¼����
void studentMenu(Identify* &student);

// ��ʦ��¼����
void teacherMenu(Identify* &teacher);

// ����Ա��¼����
void managerMenu(Identify* &manager);

int main(){

	int select = 0;		// ��¼�����ѡ��

	// ����ѭ��
	while (true) {

		// ��ӡϵͳ����
		cout << "\t\t#################### ��ӭʹ�û���ԤԼϵͳ ####################" << endl;
		cout << endl;
		cout << "\t\t      **************************************************" << endl;
		cout << "\t\t      ********* +---------------------------+ **********" << endl;
		cout << "\t\t      ********* |       ��ȷ��������ݣ�    | **********" << endl;
		cout << "\t\t      ********* |                           | **********" << endl;
		cout << "\t\t      ********* |                           | **********" << endl;
		cout << "\t\t      ********* |        1�� ѧ  ��         | **********" << endl;
		cout << "\t\t      ********* |                           | **********" << endl;
		cout << "\t\t      ********* |        2�� ��  ʦ         | **********" << endl;
		cout << "\t\t      ********* |                           | **********" << endl;
		cout << "\t\t      ********* |        3�� ����Ա         | **********" << endl;
		cout << "\t\t      ********* |                           | **********" << endl;
		cout << "\t\t      ********* |        0�� ��  ��         | **********" << endl;
		cout << "\t\t      ********* |                           | **********" << endl;
		cout << "\t\t      ********* |                           | **********" << endl;
		cout << "\t\t      ********* +---------------------------+ **********" << endl;
		cout << "\t\t      **************************************************" << endl;
		cout << "\t\t      **************************************************" << endl;

		cout << endl;
		cout << "###����������ѡ��" << endl;

		cin >> select;

		switch (select)
		{
		case 1:
			// ѧ����ݵ���
			login(STUDENT_FILE, 1);
			break;

		case 2:
			// ��ʦ��ݵ���
			login(TEACHER_FILE, 2);
			break;

		case 3:
			// ����Ա��ݵ���
			login(ADMIN_FILE, 3);
			break;
		
		case 0:
			cout << "###�ڴ����´�ʹ��" << endl;
			system("pause");
			return 0;
			break;

		default:
			cerr << "!!!������������������" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	
}

// ��¼ǰ������
void login(string filePath, int select)
{
	// ����Ϣ�ļ�
	ifstream ifs;
	ifs.open(filePath, ios::in);

	// �ж��ļ��Ƿ��
	if (!ifs.is_open()) {
		// �ļ���ʧ��
		cerr << "!!!�ļ���ʧ��" << endl;
		system("pause");
		system("cls");
		return;
	}

	// ��̬���ָ��
	Identify* identify = NULL;

	// �ж�ѡ�����ݣ�����֤���
	int id = 0;
	string name;
	string pwd;

	if (select == 1) {
		cout << "����������ѧ�ţ�" << endl;
		cin >> id;
	}
	else if (select == 2) {
		cout << "���������Ľ�ʦ�ţ�" << endl;
		cin >> id;
	}

	cout << "�������û�����" << endl;
	cin >> name;

	cout << "���������룺" << endl;
	cin >> pwd;

	if (select == 1) {
		// �����ļ���Ϣ
		int fId = 0;
		string fName;
		string fPwd;

		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "###ѧ����¼�ɹ�" << endl;
				system("pause");
				system("cls");

				identify = new Student(id, name, pwd);
				// ��ѧ������
				studentMenu(identify);
				ifs.close();	// �ر��ļ���
				return;
			}
		}
	}
	else if (select == 2) {
		// �����ļ���Ϣ
		int fId = 0;
		string fName;
		string fPwd;

		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {

			if (fId == id && fName == name && fPwd == pwd) {
				cout << "###��ʦ��¼�ɹ�" << endl;
				system("pause");
				system("cls");

				identify = new Teacher(id, name, pwd);
				// �򿪽�ʦ����

				ifs.close();	// �ر��ļ���
				return;
			}
		}
	}
	else if (select == 3) {
		// �����ļ���Ϣ
		int fId = 0;
		string fName;
		string fPwd;

		while (ifs >> fName && ifs >> fPwd) {

			if (fName == name && fPwd == pwd) {
				cout << "###����Ա��¼�ɹ�" << endl;
				system("pause");
				system("cls");

				identify = new Manager(name, pwd);
				// �򿪹���Ա����
				managerMenu(identify);
				ifs.close();	// �ر��ļ���
				return;
			}
		}
	}

	// �����֤ʧ��
	cerr << "!!!�û������֤ʧ��" << endl;
	ifs.close();	// �ر��ļ���

	system("pause");
	system("cls");
	return;
}

// ѧ����¼����
void studentMenu(Identify*& student)
{
	// ָ��ת�����ͣ�ʹ���Ե���������к���
	Student* stu = (Student*)student;

	while (true) {
		// ���ò˵�����
		stu->showMenu();

		// ����ָ���������Ӧ
		int command = 0;	// �洢ָ��

		cin >> command;

		switch (command)
		{
		case 1:
			// ����ԤԼ
			stu->applyOrder();
			break;

		case 2:
			// �鿴�Լ���ԤԼ
			stu->showMyOrder();
			break;

		case 3:
			// �鿴����ԤԼ���
			stu->showAllOrder();
			break;

		case 4:
			// ȡ��ԤԼ
			stu->cancelOrder();
			break;

		case 0:
			// �˳���¼
			cout << "###�˳���¼�ɹ�" << endl;
			system("pause");
			system("cls");
			return;

		default:
			// �������
			cerr << "!!!������������������" << endl;
			system("pause");
			system("cls");
		}
	}
}

// ����Ա��¼����
void managerMenu(Identify* &manager)
{
	// ָ��ת�����ͣ�ʹ���Ե���������к���
	Manager* man = (Manager*)manager;

	while (true) {
		// ���ò˵�����
		man->showMenu();

		// ����ָ���������Ӧ
		int command = 0;	// �洢ָ��

		cin >> command;

		switch (command)
		{
		case 1:
			// �鿴�˺�
			man->showAllUser();
			break;

		case 2:
			// ����˺�
			man->addUser();
			break;

		case 3:
			// �鿴������Ϣ
			man->showCptRoom();
			break;

		case 4:
			// �������ԤԼ��¼
			man->cleanOrder();
			break;

		case 0:
			// �˳���¼
			cout << "###�˳���¼�ɹ�" << endl;
			system("pause");
			system("cls");
			return;

		default:
			// �������
			cerr << "!!!������������������" << endl;
			system("pause");
			system("cls");
		}
	}

}
