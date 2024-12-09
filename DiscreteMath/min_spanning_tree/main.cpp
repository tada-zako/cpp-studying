/*
	��С������ Kruskal's �㷨��̰���㷨
	�����б߰���Ȩ�����򣬴ӵ͵������α����ߣ���߼��뵽���в����γɻ����򽫱���ӵ�����С��������

	���鼯��(UnionFind) �����ϲ�Ԫ�أ������뵽���е�Ԫ�غϲ���ͬһ��������
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ������  �ߺ��ڽӵĶ���
struct EdgeWithver {
	int u, v, w;	// ����1 ����2 ��Ȩ��
	bool operator<(const EdgeWithver& other) const {
		// ν�ʺ���  ����Ȩ���������� ewv
		return w < other.w;	// ��������
	}
};

// ���鼯��
class UnionFind {
public:
	// ���캯��
	UnionFind(int n) : parent(n), rank(n, 0) {
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
	}

	// ���Һ���  ����ÿ��Ԫ�صĸ�������
	int find(int n) {
		if (parent[n] != n) {
			// ������Ԫ�صĸ������ϲ��Ǳ���
			parent[n] = find(parent[n]);	// ���¸�����  ��ʵʱӳ��
		}
		return parent[n];	// ���ظ�����������
	}

	// �ϲ�����  ��ѡ����Ԫ����ӵ�ͬһ��������
	bool unite(int u, int v) {
		// �жϸ���Ԫ���Ƿ�λ��ͬһ������
		int rootU = find(u);	// u �ĸ�������
		int rootV = find(v);	// v �ĸ�������

		if (rootU != rootV) {
			// ���Ԫ�ص�ͬһ����
			if (rank[rootU] < rank[rootV]) {
				parent[rootU] = rootV;	// ��С���Ϻϲ����󼯺���  ����С���ϵĸ�������Ϊ�󼯺�
				rank[rootV]++;	// ���ϴ�С�� 1
			}
			else if (rank[rootU] > rank[rootV]) {
				parent[rootV] = rootU;	// ��С���Ϻϲ����󼯺���  ����С���ϵĸ�������Ϊ�󼯺�
				rank[rootU]++;	// ���ϴ�С�� 1
			}
			else {
				parent[rootV] = rootU;
				rank[rootU]++;	// ���ϴ�С�� 1
			}
			return true;	// �ϲ��ɹ�
		}

		return false;	// �ϲ�ʧ��
	}

private:
	vector<int> parent;		// ������  �洢ÿ��Ԫ�ض�Ӧ�ļ�������  �� parent[1] = 2  ->  1 ��Ԫ��λ�� 2 �ż�����
	vector<int> rank;	// �������  �洢ÿ�����ϵĴ�С
};

int Kruskal(int n, vector<EdgeWithver>& graph) {
	// ��ͼ����Ȩ����������
	sort(graph.begin(), graph.end());
	// ���ɲ��鼯
	UnionFind uf(n + 1);	// ����� 1 ��ʼ����
	int minWeight = 0;	// ��СȨ��	
	int edgeCount = 0;	// �������߼���

	// ѭ��������
	for (const auto& edge : graph) {
		if (uf.unite(edge.u, edge.v)) {
			// �ϲ��ɹ�
			minWeight += edge.w;
			edgeCount++;
			if (edgeCount == n - 1) {
				// �ﵽ������
				return minWeight;
			}
		}
	}

	// ����������ɲ����������������� -1
	return -1;
}

int main() {
	int n, m;	// ������  ����
	cin >> n >> m;

	vector<EdgeWithver> graph;
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		graph.push_back({ u, v, w });
	}
	int result = Kruskal(n, graph);
	cout << result << endl;
	
	return 0;
}