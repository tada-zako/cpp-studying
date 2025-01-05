#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    unordered_set<int> ballNumbers; // 存储球的编号

    // 读取 m 个球的编号
    for (int i = 0; i < m; ++i) {
        int num;
        cin >> num;
        ballNumbers.insert(num);
    }

    // 处理 n 次查询
    for (int i = 0; i < n; ++i) {
        int query;
        cin >> query;

        if (ballNumbers.count(query)) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}