#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> calculateDistances(int N_pos, int M_edge, int C_current, vector<pair<int, int>> edges) {
	vector<vector<int>> subgraphs(N_pos + 1);	// 子图：存储每个节点的邻接节点
	for (const auto edge : edges) {
		int pos_a = edge.first;
		int pos_b = edge.second;
		subgraphs[pos_a].push_back(pos_b);
		subgraphs[pos_b].push_back(pos_a);
	}

	vector<int> distance(N_pos + 1, -1);	// 距离：存储从 C 到各节点最短距离
	distance[C_current] = 0;

	queue<int> q;	// 队列：遍历所有节点
	q.push(C_current);
	
	while (!q.empty()) {
		int current = q.front();
		q.pop();

		for (const auto neighbor : subgraphs[current]) {
			if (distance[neighbor] == -1) {	// 如果还未到达
				distance[neighbor] = distance[current] + 1;
				q.push(neighbor);
			}
		}
	}

	return distance;
}

int main() {
	int N_pos = 0, M_edge = 0, C_current = 0;
	cin >> N_pos >> M_edge >> C_current;

	vector<pair<int, int>> edges(M_edge);
	for (int i = 0; i < M_edge; i++) {
		int pos_a = 0, pos_b;
		cin >> pos_a >> pos_b;
		edges[i] = { pos_a, pos_b };
	}

	vector<int> distance = calculateDistances(N_pos, M_edge, C_current, edges);

	for (int i = 1; i <= N_pos; ++i) {
		cout << distance[i] << endl;
	}
}