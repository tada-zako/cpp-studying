#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
	int n = 0, m = 0;	// ��ľ��  ������
	cin >> n >> m;
	vector<stack<int>> block(n + 1);	// ��ľ����

	// ��ʼ������
	for (int i = 1; i <= n; i++) {
		block[i].push(i);
	}

	// ִ��λ�Ʋ���
	int a = 0, b = 0;	// ĩλ��  ��λ��
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		// a=b ������
		if (a != b) {
			stack<int> temp;	// �ݴ��ջ����
			while (!block[b].empty()) {
				temp.push(block[b].top());
				block[b].pop();
			}
			while (!temp.empty()) {		// λ�Ʋ���
				block[a].push(temp.top());
				temp.pop();
			}
		}
	}

	// �������
	for (int i = 1; i <= n; i++) {
		vector<int> output;	// ����洢stack��ջ������
		while (!block[i].empty()) {
			output.push_back(block[i].top());
			block[i].pop();
		}
		// �������output�洢������
		for (auto it = output.rbegin(); it != output.rend(); it++) {
			cout << *it << (it + 1 == output.rend() ? '\n' : ' ');
		}
		// ���outputΪ�գ��������
		if (output.empty()) {
			cout << endl;
		}
	}
}