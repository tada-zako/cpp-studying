#pragma once
#include <iostream>
#include "Identify.h"

using namespace std;

class Teacher :public Identify
{
public:
	Teacher();
	Teacher(int id, string name, string pwd);

	virtual void showMenu();	// չʾ�û������麯��

	// �鿴����ԤԼ
	void showAllOrder();

	// ���ԤԼ
	void verifyOrder();

	// �˳���¼
	void logOff();


public:
	int teaId;		// ��ʦ��

};