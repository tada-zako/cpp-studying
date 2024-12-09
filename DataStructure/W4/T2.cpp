#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
	int n = 0, m = 0;	// 积木数  操作数
	cin >> n >> m;
	vector<stack<int>> block(n + 1);	// 积木容器

	// 初始化容器
	for (int i = 1; i <= n; i++) {
		block[i].push(i);
	}

	// 执行位移操作
	int a = 0, b = 0;	// 末位置  初位置
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		// a=b 不操作
		if (a != b) {
			stack<int> temp;	// 暂存出栈数据
			while (!block[b].empty()) {
				temp.push(block[b].top());
				block[b].pop();
			}
			while (!temp.empty()) {		// 位移操作
				block[a].push(temp.top());
				temp.pop();
			}
		}
	}

	// 输出数据
	for (int i = 1; i <= n; i++) {
		vector<int> output;	// 逆序存储stack出栈的数据
		while (!block[i].empty()) {
			output.push_back(block[i].top());
			block[i].pop();
		}
		// 逆序输出output存储的数据
		for (auto it = output.rbegin(); it != output.rend(); it++) {
			cout << *it << (it + 1 == output.rend() ? '\n' : ' ');
		}
		// 如果output为空，输出空行
		if (output.empty()) {
			cout << endl;
		}
	}
}