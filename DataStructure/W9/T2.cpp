#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
    int N, K;
    cin >> N;

    vector<int> scores(N);
    // 输入分数
    for (int i = 0; i < N; ++i) {
        cin >> scores[i];
    }

    cin >> K;

    // 对分数从高到低排序
    sort(scores.begin(), scores.end(), greater<int>());

    // 计算前 K 名的总分
    double sum = 0;
    for (int i = 0; i < K; ++i) {
        sum += scores[i];
    }

    // 计算平均分
    double average = sum / K;

    // 输出保留两位小数
    cout << fixed << setprecision(2) << average << endl;

    return 0;
}
