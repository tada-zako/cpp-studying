#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// �ز�����ʵ��
vector<int> findTopologicalOrder(int n, vector<pair<int, int>>constraints) {
	vector<vector<int>> adjDiag(n + 1);	// �ڽ�ͼ
	vector<int> inDegree(n + 1, 0);	// ��ȱ�

	// �����ڽ�ͼ  ����ÿ���ڵ�����
	for (const auto& constraint : constraints) {
		int x = constraint.first;
		int y = constraint.second;
		adjDiag[x].push_back(y);
		inDegree[y]++;
	}


	priority_queue<int> maxHeap; // ����һ�����ѣ���������
	// �������Ϊ 0 �Ľڵ�
	for (int i = 1; i < n + 1; i++) {
		if (inDegree[i] == 0) {
			maxHeap.push(i);
		}
	}

	vector<int> topologicalOrder;	// �ز�����˳��
	while (!maxHeap.empty()) {
		int minNode = maxHeap.top();
		maxHeap.pop();
		topologicalOrder.push_back(minNode);

		// ���½ڵ����  ����С��
		for (const auto& node : adjDiag[minNode]) {
			inDegree[node]--;
			if (inDegree[node] == 0) {
				maxHeap.push(node);
			}
		}
	}

	// ����������Ĵ�СС�ڽڵ�����˵��ͼ���л�
	if (topologicalOrder.size() < n) {
		return {}; // ���ؿս������ʾ�޷������������
	}

	return topologicalOrder;
}

int main() {
	int D_counter = 0;
	cin >> D_counter;

	while (D_counter--) {
		int N_dishes = 0, M_constraints = 0;
		cin >> N_dishes >> M_constraints;

		// �洢��������
		vector<pair<int, int>> constraints(M_constraints);
		for (int i = 0; i < M_constraints; i++) {
			int x, y;
			cin >> x >> y;
			constraints[i] = { x, y };
		}

		// ʹ���ز�����õ�������
		vector<int> result = findTopologicalOrder(N_dishes, constraints);

		// ���ݽ�����
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