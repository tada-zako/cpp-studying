#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {

	int N;	// 输入序列长度
	cin >> N;

	vector<int> target_order(N);		// 目标序列

	for (int i = 0; i < N; i++) {
		cin >> target_order[i];
	}

	// 创建栈，逐个压入元素，直到栈顶元素和目标序列相同
	stack<int> s;
	int j = 0;	// 指向目标序列对应元素位置

	for (int i = 1; i <= N; i++) {
		// 压入元素
		s.push(i);
		// 判断栈顶是否与序列元素相同
		while (!s.empty() && s.top() == target_order[j]) {
			s.pop();
			j++;
		}
	}

	if (j == N) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}