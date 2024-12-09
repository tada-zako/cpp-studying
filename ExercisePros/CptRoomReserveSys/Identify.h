#pragma once
#include <iostream>
#include <fstream>
#include <vector>

#include "Global.h"
#include "ComputerRoom.h"

using namespace std;

/* 用户身份基类 */
class Identify {
	
public:
	virtual void showMenu() = 0;	// 展示用户界面虚函数

public:
	string userName;	// 用户名
	string userPwd;		// 用户密码

};