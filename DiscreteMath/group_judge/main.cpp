/*
	群的判定：1.运算封闭，D 中任意元素 a b 和 mod 运算后结果在 D 中;
			  2.存在单位元 e ，使任意 a ，存在 (a + e) mod M = a;
			  3.对于任意元素 a ，存在一个逆元 b ，满足 (a + b) mod M = e;
*/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

int main() {
	
	// 存储集合 D 中元素
	string line;	// 输入流 读取一行内容
	int num;	// 读入的数字
	unordered_set<int> mapping;		// 映射表 用于查找元素
	vector<int> D;	// 存储数字的容器

	bool isGroup = true;	// 判定是否是群

	// 读取输入的元素，并存入容器中
	getline(cin, line);
	istringstream iss(line);
	while (iss >> num) {
		if (mapping.find(num) == mapping.end()) {
			// 映射表不存在元素
			mapping.insert(num);
			D.push_back(num);
		}
	}
	// 读入 M
	int M;
	cin >> M;

	// 判定1.运算是否封闭
	bool isClosed = true;	// 是否封闭
	for (const auto num1 : mapping) {
		for (const auto num2 : mapping) {
			if (mapping.find((num1 + num2) % M) == mapping.end()) {	// 查找计算后结果是否在容器中
				isClosed = false;
				break;
			}
		}

		if (!isClosed) {
			// 运算不封闭，退出判定
			isGroup = false;
			break;
		}
	}

	// 判定2.是否存在单位元 e
	int e = 0;	// 单位元
	for (const auto num1 : mapping) {
		bool validIdentity = true;	// 有无单位元
		isGroup = false;
		for (const auto num2 : mapping) {
			if ((num2 + num1) % M != num2) {
				// 不是单位元
				validIdentity = false;
				break;
			}
		}

		if (validIdentity) {
			// 找到单位元
			e = num1;
			isGroup = true;
			break;
		}
	}

	// 判定3.是否存在逆元
	if (isGroup) 
	{
		bool hasInverse = false;	// 逆元存在判定
		for (const auto num1 : mapping) {
			for (const auto num2 : mapping) {
				if ((num1 + num2) % M == e) {
					// 存在逆元
					hasInverse = true;
					break;
				}
			}

			if (!hasInverse) {
				// 没有逆元情况
				isGroup = false;
				break;
			}
		}
	}

	// 输出结果
	if (isGroup) {
		sort(D.begin(), D.end());	// 容器元素排序
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