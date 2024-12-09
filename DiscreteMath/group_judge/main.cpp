/*
	Ⱥ���ж���1.�����գ�D ������Ԫ�� a b �� mod ��������� D ��;
			  2.���ڵ�λԪ e ��ʹ���� a ������ (a + e) mod M = a;
			  3.��������Ԫ�� a ������һ����Ԫ b ������ (a + b) mod M = e;
*/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

int main() {
	
	// �洢���� D ��Ԫ��
	string line;	// ������ ��ȡһ������
	int num;	// ���������
	unordered_set<int> mapping;		// ӳ��� ���ڲ���Ԫ��
	vector<int> D;	// �洢���ֵ�����

	bool isGroup = true;	// �ж��Ƿ���Ⱥ

	// ��ȡ�����Ԫ�أ�������������
	getline(cin, line);
	istringstream iss(line);
	while (iss >> num) {
		if (mapping.find(num) == mapping.end()) {
			// ӳ�������Ԫ��
			mapping.insert(num);
			D.push_back(num);
		}
	}
	// ���� M
	int M;
	cin >> M;

	// �ж�1.�����Ƿ���
	bool isClosed = true;	// �Ƿ���
	for (const auto num1 : mapping) {
		for (const auto num2 : mapping) {
			if (mapping.find((num1 + num2) % M) == mapping.end()) {	// ���Ҽ�������Ƿ���������
				isClosed = false;
				break;
			}
		}

		if (!isClosed) {
			// ���㲻��գ��˳��ж�
			isGroup = false;
			break;
		}
	}

	// �ж�2.�Ƿ���ڵ�λԪ e
	int e = 0;	// ��λԪ
	for (const auto num1 : mapping) {
		bool validIdentity = true;	// ���޵�λԪ
		isGroup = false;
		for (const auto num2 : mapping) {
			if ((num2 + num1) % M != num2) {
				// ���ǵ�λԪ
				validIdentity = false;
				break;
			}
		}

		if (validIdentity) {
			// �ҵ���λԪ
			e = num1;
			isGroup = true;
			break;
		}
	}

	// �ж�3.�Ƿ������Ԫ
	if (isGroup) 
	{
		bool hasInverse = false;	// ��Ԫ�����ж�
		for (const auto num1 : mapping) {
			for (const auto num2 : mapping) {
				if ((num1 + num2) % M == e) {
					// ������Ԫ
					hasInverse = true;
					break;
				}
			}

			if (!hasInverse) {
				// û����Ԫ���
				isGroup = false;
				break;
			}
		}
	}

	// ������
	if (isGroup) {
		sort(D.begin(), D.end());	// ����Ԫ������
		for (const auto num1 : D) {
			for (const auto num2 : D) {
				if ((num1 + num2) % M == e) {
					cout << num1 << " " << num2 << endl;
					break;
				}
			}
		}
	}
	else {
		cout << -1 << endl;
	}
}