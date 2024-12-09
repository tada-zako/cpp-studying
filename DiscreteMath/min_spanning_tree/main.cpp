/*
	最小生成树 Kruskal's 算法：贪心算法
	将所有边按照权重排序，从低到高依次遍历边，如边加入到树中不会形成环，则将边添加到到最小生成树中

	并查集：(UnionFind) 用来合并元素，将加入到树中的元素合并到同一个集合中
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 构造体  边和邻接的顶点
struct EdgeWithver {
	int u, v, w;	// 顶点1 顶点2 边权重
	bool operator<(const EdgeWithver& other) const {
		// 谓词函数  根据权重排序构造体 ewv
		return w < other.w;	// 升序排序
	}
};

// 并查集类
class UnionFind {
public:
	// 构造函数
	UnionFind(int n) : parent(n), rank(n, 0) {
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
	}

	// 查找函数  查找每个元素的父级集合
	int find(int n) {
		if (parent[n] != n) {
			// 当查找元素的父级集合不是本身
			parent[n] = find(parent[n]);	// 更新父级表  非实时映射
		}
		return parent[n];	// 返回父级集合坐标
	}

	// 合并函数  将选定的元素添加到同一个集合中
	bool unite(int u, int v) {
		// 判断给定元素是否位于同一个集合
		int rootU = find(u);	// u 的父级坐标
		int rootV = find(v);	// v 的父级坐标

		if (rootU != rootV) {
			// 添加元素到同一集合
			if (rank[rootU] < rank[rootV]) {
				parent[rootU] = rootV;	// 将小集合合并到大集合中  更新小集合的父级坐标为大集合
				rank[rootV]++;	// 集合大小加 1
			}
			else if (rank[rootU] > rank[rootV]) {
				parent[rootV] = rootU;	// 将小集合合并到大集合中  更新小集合的父级坐标为大集合
				rank[rootU]++;	// 集合大小加 1
			}
			else {
				parent[rootV] = rootU;
				rank[rootU]++;	// 集合大小加 1
			}
			return true;	// 合并成功
		}

		return false;	// 合并失败
	}

private:
	vector<int> parent;		// 父级表  存储每个元素对应的集合坐标  如 parent[1] = 2  ->  1 号元素位于 2 号集合中
	vector<int> rank;	// 集合深度  存储每个集合的大小
};

int Kruskal(int n, vector<EdgeWithver>& graph) {
	// 将图按照权重升序排列
	sort(graph.begin(), graph.end());
	// 生成并查集
	UnionFind uf(n + 1);	// 顶点从 1 开始计数
	int minWeight = 0;	// 最小权重	
	int edgeCount = 0;	// 生成树边计数

	// 循环生成树
	for (const auto& edge : graph) {
		if (uf.unite(edge.u, edge.v)) {
			// 合并成功
			minWeight += edge.w;
			edgeCount++;
			if (edgeCount == n - 1) {
				// 达到生成树
				return minWeight;
			}
		}
	}

	// 如果最终生成不满足树条件，返回 -1
	return -1;
}

int main() {
	int n, m;	// 顶点数  边数
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