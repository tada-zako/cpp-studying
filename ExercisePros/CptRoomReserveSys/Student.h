#pragma once
#include <iostream>
#include "Identify.h"

using namespace std;

class Student : public Identify
{
public:
	Student();
	Student(int id, string name, string pwd);	// ���ι��캯��

	virtual void showMenu();	// չʾ�û������麯��

	// ����ԤԼ
	void applyOrder();

	// �鿴�Լ���ԤԼ
	void showMyOrder();

	// �鿴����ԤԼ���
	void showAllOrder();

	// ȡ��ԤԼ
	void cancelOrder();

public:
	int stuId;	// ѧ��

};