#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 计算字符串的逆序对数量
int countInversions(const string& s) {
    int inversions = 0;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (s[i] > s[j]) {
                ++inversions;
            }
        }
    }
    return inversions;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<string, int>> dna; // 保存字符串及其逆序对数量

    // 输入字符串并计算逆序对数量
    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        int inversions = countInversions(s);
        dna.push_back({ s, inversions });
    }

    // 按逆序对数量排序，数量相同则保持输入顺序
    stable_sort(dna.begin(), dna.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.second < b.second;
        });

    // 输出排序后的字符串
    for (const auto& p : dna) {
        cout << p.first << endl;
    }

    return 0;
}
