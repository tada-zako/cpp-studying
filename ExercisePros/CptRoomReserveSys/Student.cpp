#include "Student.h"

Student::Student()
{}

Student::Student(int id, string name, string pwd)	// ���ι��캯��
{
	this->stuId = id;
	this->userName = name;
	this->userPwd = pwd;

}

void Student::showMenu()	// չʾ�û������麯��
{
	// ��ӡϵͳ����
	cout << "\t\t    #################### ��ӭ" << this->userName << "��¼ ####################" << endl;
	cout << endl;
	cout << "\t\t      **************************************************" << endl;
	cout << "\t\t      ********* +---------------------------+ **********" << endl;
	cout << "\t\t      ********* |       ��ȷ�����Ĳ�����    | **********" << endl;
	cout << "\t\t      ********* |                           | **********" << endl;
	cout << "\t\t      ********* |                           | **********" << endl;
	cout << "\t\t      ********* |       1�� ����ԤԼ        | **********" << endl;
	cout << "\t\t      ********* |                           | **********" << endl;
	cout << "\t\t      ********* |      2���鿴����ԤԼ      | **********" << endl;
	cout << "\t\t      ********* |                           | **********" << endl;
	cout << "\t\t      ********* |      3���鿴����ԤԼ      | **********" << endl;
	cout << "\t\t      ********* |                           | **********" << endl;
	cout << "\t\t      ********* |       4�� ȡ��ԤԼ        | **********" << endl;
	cout << "\t\t      ********* |                           | **********" << endl;
	cout << "\t\t      ********* |        0�� ��  ��         | **********" << endl;
	cout << "\t\t      ********* |                           | **********" << endl;
	cout << "\t\t      ********* |                           | **********" << endl;
	cout << "\t\t      ********* +---------------------------+ **********" << endl;
	cout << "\t\t      **************************************************" << endl;
	cout << "\t\t      **************************************************" << endl;

	cout << endl;
	cout << "###����������ѡ��" << endl;
}

// ����ԤԼ
void Student::applyOrder()
{

}

// �鿴�Լ���ԤԼ
void Student::showMyOrder()
{

}

// �鿴����ԤԼ���
void Student::showAllOrder()
{

}

// ȡ��ԤԼ
void Student::cancelOrder()
{

}
