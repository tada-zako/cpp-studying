#pragma once
#include <iostream>
#include <fstream>
#include <vector>

#include "Global.h"
#include "ComputerRoom.h"

using namespace std;

/* �û���ݻ��� */
class Identify {
	
public:
	virtual void showMenu() = 0;	// չʾ�û������麯��

public:
	string userName;	// �û���
	string userPwd;		// �û�����

};