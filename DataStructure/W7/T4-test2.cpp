#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

// ����������
vector<int> topologicalSort(int n, const vector<pair<int, int>>& edges) {
    vector<vector<int>> graph(n + 1); // �ڽӱ��ʾͼ
    vector<int> inDegree(n + 1, 0);   // ��¼ÿ���ڵ�����

    // ����ͼ�ͼ������
    for (const auto& edge : edges) {
        int u = edge.first, v = edge.second;
        graph[u].push_back(v);
        inDegree[v]++;
    }

    // ���ȶ��У�С���ѣ�����֤�ֵ�����С
    priority_queue<int, vector<int>> pq;

    // �����Ϊ 0 �Ľڵ�������
    for (int i = 1; i <= n; ++i) {
        if (inDegree[i] == 0) {
            pq.push(i);
        }
    }

    vector<int> result;

    // ��������
    while (!pq.empty()) {
        int curr = pq.top();
        pq.pop();
        result.push_back(curr);

        // ������ǰ�ڵ���ڽӵ�
        for (int neighbor : graph[curr]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                pq.push(neighbor);
            }
        }
    }

    // �������нڵ��������� n��˵�����ڻ������ؿս��
    if (result.size() != n) {
        return {};
    }

    return result;
}

int main() {
    int D; // ��������
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

        // ������������
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
