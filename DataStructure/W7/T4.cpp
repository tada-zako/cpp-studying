#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 拓补排序实现
vector<int> findTopologicalOrder(int n, vector<pair<int, int>>constraints) {
	vector<vector<int>> adjDiag(n + 1);	// 邻接图
	vector<int> inDegree(n + 1, 0);	// 入度表

	// 绘制邻接图  计算每个节点的入度
	for (const auto& constraint : constraints) {
		int x = constraint.first;
		int y = constraint.second;
		adjDiag[x].push_back(y);
		inDegree[y]++;
	}


	priority_queue<int> maxHeap; // 创建一个最大堆（降序排序）
	// 存入入度为 0 的节点
	for (int i = 1; i < n + 1; i++) {
		if (inDegree[i] == 0) {
			maxHeap.push(i);
		}
	}

	vector<int> topologicalOrder;	// 拓补排序顺序
	while (!maxHeap.empty()) {
		int minNode = maxHeap.top();
		maxHeap.pop();
		topologicalOrder.push_back(minNode);

		// 更新节点入度  和最小堆
		for (const auto& node : adjDiag[minNode]) {
			inDegree[node]--;
			if (inDegree[node] == 0) {
				maxHeap.push(node);
			}
		}
	}

	// 如果排序结果的大小小于节点数，说明图中有环
	if (topologicalOrder.size() < n) {
		return {}; // 返回空结果，表示无法完成拓扑排序
	}

	return topologicalOrder;
}

int main() {
	int D_counter = 0;
	cin >> D_counter;

	while (D_counter--) {
		int N_dishes = 0, M_constraints = 0;
		cin >> N_dishes >> M_constraints;

		// 存储限制条件
		vector<pair<int, int>> constraints(M_constraints);
		for (int i = 0; i < M_constraints; i++) {
			int x, y;
			cin >> x >> y;
			constraints[i] = { x, y };
		}

		// 使用拓补排序得到排序结果
		vector<int> result = findTopologicalOrder(N_dishes, constraints);

		// 根据结果输出
		if (result.empty()) {
			cout << "Impossible!" << endl;
		}
		else {
			for (const int node : result) {
				cout << node << ' ';
			}
			cout << endl;
		}
	}
	
}