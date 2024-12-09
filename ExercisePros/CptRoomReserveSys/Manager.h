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

	virtual void showMenu();	// չʾ�û������麯��

	// �鿴�˺�
	void showAllUser();

	// ����˺�
	void addUser();

	// �鿴������Ϣ
	void showCptRoom();

	// �������ԤԼ��¼
	void cleanOrder();

	// ��ʼ���洢����
	void initVec();

	// ��ʼ��������Ϣ
	void initCrVec();

	// ����Ƿ���id���ظ�
	bool checkIdRepeat(int id, int type);


public:
	vector<Student> stuVec;		// �洢����ѧ���˻�����
	vector<Teacher> teaVec;		// �洢���н�ʦ�˻�����

	vector<ComputerRoom> crVec;		// �洢���л�����Ϣ
};