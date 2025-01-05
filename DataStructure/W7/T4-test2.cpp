#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

// 拓扑排序函数
vector<int> topologicalSort(int n, const vector<pair<int, int>>& edges) {
    vector<vector<int>> graph(n + 1); // 邻接表表示图
    vector<int> inDegree(n + 1, 0);   // 记录每个节点的入度

    // 构建图和计算入度
    for (const auto& edge : edges) {
        int u = edge.first, v = edge.second;
        graph[u].push_back(v);
        inDegree[v]++;
    }

    // 优先队列（小顶堆），保证字典序最小
    priority_queue<int, vector<int>> pq;

    // 将入度为 0 的节点加入队列
    for (int i = 1; i <= n; ++i) {
        if (inDegree[i] == 0) {
            pq.push(i);
        }
    }

    vector<int> result;

    // 拓扑排序
    while (!pq.empty()) {
        int curr = pq.top();
        pq.pop();
        result.push_back(curr);

        // 遍历当前节点的邻接点
        for (int neighbor : graph[curr]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                pq.push(neighbor);
            }
        }
    }

    // 如果结果中节点数不等于 n，说明存在环，返回空结果
    if (result.size() != n) {
        return {};
    }

    return result;
}

int main() {
    int D; // 数据组数
    cin >> D;

    while (D--) {
        int N, M;
        cin >> N >> M;

        vector<pair<int, int>> edges;

        for (int i = 0; i < M; ++i) {
            int x, y;
            cin >> x >> y;
            edges.emplace_back(x, y);
        }

        // 调用拓扑排序
        vector<int> order = topologicalSort(N, edges);

        if (order.empty()) {
            cout << "Impossible!" << endl;
        }
        else {
            for (int i = 0; i < order.size(); ++i) {
                if (i > 0) cout << " ";
                cout << order[i];
            }
            cout << endl;
        }
    }

    return 0;
}
