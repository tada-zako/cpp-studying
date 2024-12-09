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
	// ��ȡ����
	while (getline(cin, line)) {
		// �ж��������
		if (line.empty()) {
			break;
		}

		// ��������
		istringstream iss(line);
		int type;
		string number;
		iss >> type >> number;

		// �����洢��ͬ�����ֻ���
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

	// �洢�������� 10������ 0
	while (number_0.size() < 10) {
		number_0.push_back("0");
	}
	while (number_1.size() < 10) {
		number_1.push_back("0");
	}
	while (number_2.size() < 10) {
		number_2.push_back("0");
	}


	// ��ӡ����
	for (int i = 0; i < 10; i++) {
		cout << number_0[i] << " " << number_1[i] << " " << number_2[i] << endl;
	}
}