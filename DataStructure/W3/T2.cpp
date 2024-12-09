#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {

	int N;	// �������г���
	cin >> N;

	vector<int> target_order(N);		// Ŀ������

	for (int i = 0; i < N; i++) {
		cin >> target_order[i];
	}

	// ����ջ�����ѹ��Ԫ�أ�ֱ��ջ��Ԫ�غ�Ŀ��������ͬ
	stack<int> s;
	int j = 0;	// ָ��Ŀ�����ж�ӦԪ��λ��

	for (int i = 1; i <= N; i++) {
		// ѹ��Ԫ��
		s.push(i);
		// �ж�ջ���Ƿ�������Ԫ����ͬ
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