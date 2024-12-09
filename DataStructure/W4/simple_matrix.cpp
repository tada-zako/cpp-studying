#include <iostream>
#include <vector>
using namespace std;


int main() {
	// �����򵥶�ά����ʵ�־����С��л���
	int n = 0, m = 0;	// �С�����
	cin >> n >> m;

	vector<vector<int>>matrix(n, vector<int>(m));	// ��λ����
	// ����ֵ
	for (auto& row : matrix){
		for (auto& cal : row) {
			cin >> cal;
		}
	}

	// ��ӡ����
	//for (auto& row : matrix) {
	//	for (auto& cal : row) {
	//		cout << cal;
	//	}
	//}

	// ��ȡ����
	int op = 0, x = 0, y = 0, z = 0;	// ��������   ������   ��/��
	cin >> op;
	for (int i = 0; i < op; i++) {
		cin >> x >> y >> z;
		// ���� y z ����
		y--;
		z--;

		// �Ծ������
		if (x == 0) {
			swap(matrix[y], matrix[z]);	// ���� y z ��
		}
		else if (x == 1) {
			// ���� y z ��
			for (auto& row : matrix) {
				swap(row[y], row[z]);
			}
		}
	}

	// ��ӡ����
	for (const auto& row : matrix) {
		for (int j = 0; j < m; ++j) {
			cout << row[j] << (j == m - 1 ? '\n' : ' ');
		}
	}
}