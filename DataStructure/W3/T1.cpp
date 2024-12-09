#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main() {

	vector<string> number_0;
	vector<string> number_1;
	vector<string> number_2;

	string line;
	// 读取输入
	while (getline(cin, line)) {
		// 判断输入结束
		if (line.empty()) {
			break;
		}

		// 处理输入
		istringstream iss(line);
		int type;
		string number;
		iss >> type >> number;

		// 容器存储不同类型手机号
		switch (type)
		{
		case 0:
			number_0.push_back(number);
			break;
		case 1:
			number_1.push_back(number);
			break;
		case 2:
			number_2.push_back(number);
			break;
		default:
			break;
		}
	}

	// 存储数量不足 10，往后补 0
	while (number_0.size() < 10) {
		number_0.push_back("0");
	}
	while (number_1.size() < 10) {
		number_1.push_back("0");
	}
	while (number_2.size() < 10) {
		number_2.push_back("0");
	}


	// 打印号码
	for (int i = 0; i < 10; i++) {
		cout << number_0[i] << " " << number_1[i] << " " << number_2[i] << endl;
	}
}