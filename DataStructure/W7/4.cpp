#include <cmath>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100001;
priority_queue<int> q;
int n, m, ecnt, nxt[N], adj[N], go[N], cnt[N], ans[N];
void add_edge(int u, int v) {
    nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v; cnt[v]++;
}
int main() {
    int num;
    cin >> num;
    while (num--) {
        int i, x, y, tot = 0;
        ecnt = 0;
        memset(adj, 0, sizeof(adj));
        memset(cnt, 0, sizeof(cnt));
        cin >> n;
        cin >> m;
        bool flag = 0;
        for (i = 1; i <= m; i++) {
            cin >> x;
            cin >> y;
            add_edge(y, x); if (x == y) flag = 1;
        }
        if (flag) {
            cout << "Impossible!" << endl;
            continue;
        }
        for (i = 1; i <= n; i++)
            if (!cnt[i])
                q.push(i);
        while (!q.empty()) {
            int u = q.top(); q.pop(); ans[++tot] = u;
            for (int e = adj[u], v; e; e = nxt[e])
                if (!(--cnt[v = go[e]]))
                    q.push(v);
        }
        if (tot < n) {
            cout << "Impossible!" << endl;
            continue;
        }
        for (i = n; i; i--)
            cout << ans[i] << ' ';
        cout << endl;
    }
    return 0;
}