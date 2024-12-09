#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

// 并查集
class UnionFind {
public:
	UnionFind(int n) :parent(n), rank(n, 0) {
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
	}

	// 查找函数：查找 node 的父节点
	int find(int node) {
		if (parent[node] != node) {
			parent[node] = find(parent[node]);	// 压缩查找路径，将子节点通过递归直接连接到父节点
		}
		return parent[node];
	}

	// 合并函数：将低 rank 集合连接到高 rank 集合
	bool unionSet(int node_a, int node_b) {
		int parent_a = find(node_a);
		int parent_b = find(node_b);
		
		if (parent_a != parent_b) {
			if (rank[parent_a] > rank[parent_b]) {
				parent[parent_b] = parent_a;
			}
			else if (rank[parent_a] < rank[parent_b]) {
				parent[parent_a] = parent_b;
			}
			else {
				parent[parent_b] = parent_a;
				rank[parent_a]++;
			}
			return true;
		}
		return false;
	}

private:
	vector<int> parent;	// 父节点：记录每个节点的父节点
	vector<int> rank;	// 树高：记录每个集合的树高
};

int Kruskal(int N_country, int M_road, vector<tuple<int, int, int>> edges) {
	UnionFind uf(N_country + 1);
	int isolation_num = N_country;	// 连通分量
	int minTime = -1;

	for (const auto& edge : edges) {
		int t = 0, x = 0, y = 0;
		tie(t, x, y) = edge;

		if (uf.unionSet(x, y)) {
			isolation_num--;
			if (isolation_num == 1) {
				minTime = t;
				break;
			}
		}
	}
	return minTime;
}

int main() {
	int N_country = 0, M_road = 0;
	cin >> N_country >> M_road;

	vector<tuple<int, int, int>> edges(M_road);		// t, x, y
	for (int i = 0; i < M_road; i++) {
		int t = 0, x = 0, y = 0;
		cin >> x >> y >> t;
		edges[i] = make_tuple(t, x, y);
	}

	// 根据时间重排
	sort(edges.begin(), edges.end(), [](const auto& ele_a, const auto& ele_b) {
		return get<0>(ele_a) < get<0>(ele_b);	// 按照 tuple 中第一个元素进行比较排序
		});

	int minTime = Kruskal(N_country, M_road, edges);

	cout << minTime << endl;
}