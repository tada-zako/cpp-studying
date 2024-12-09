#include <iostream>
#include <vector>
using namespace std;


int main() {
	// 创建简单二维矩阵，实现矩阵行、列互换
	int n = 0, m = 0;	// 行、列数
	cin >> n >> m;

	vector<vector<int>>matrix(n, vector<int>(m));	// 二位矩阵
	// 矩阵赋值
	for (auto& row : matrix){
		for (auto& cal : row) {
			cin >> cal;
		}
	}

	// 打印矩阵
	//for (auto& row : matrix) {
	//	for (auto& cal : row) {
	//		cout << cal;
	//	}
	//}

	// 读取操作
	int op = 0, x = 0, y = 0, z = 0;	// 操作次数   操作数   行/列
	cin >> op;
	for (int i = 0; i < op; i++) {
		cin >> x >> y >> z;
		// 调整 y z 索引
		y--;
		z--;

		// 对矩阵操作
		if (x == 0) {
			swap(matrix[y], matrix[z]);	// 交换 y z 行
		}
		else if (x == 1) {
			// 交换 y z 列
			for (auto& row : matrix) {
				swap(row[y], row[z]);
			}
		}
	}

	// 打印矩阵
	for (const auto& row : matrix) {
		for (int j = 0; j < m; ++j) {
			cout << row[j] << (j == m - 1 ? '\n' : ' ');
		}
	}
}