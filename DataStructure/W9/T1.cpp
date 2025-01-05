#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> scores(n);
    vector<int> count(101, 0); // 分数范围为 0~100

    // 输入分数并统计每个分数的出现次数
    for (int i = 0; i < n; ++i) {
        cin >> scores[i];
        count[scores[i]]++;
    }

    // 确定至少需要的获奖人数
    int required = (n + 1) / 2; // 等价于 ceil(n / 2.0)
    int total = 0, cutoff = 0;

    // 从高分到低分累加人数，找到分数线
    for (int i = 100; i >= 0; --i) {
        total += count[i];
        if (total >= required) {
            cutoff = i;
            break;
        }
    }

    // 输出结果：分数线和获奖人数
    cout << cutoff << " " << total << endl;

    return 0;
}