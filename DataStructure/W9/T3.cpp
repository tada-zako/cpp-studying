#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// �����ַ��������������
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

    vector<pair<string, int>> dna; // �����ַ����������������

    // �����ַ������������������
    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        int inversions = countInversions(s);
        dna.push_back({ s, inversions });
    }

    // ���������������������ͬ�򱣳�����˳��
    stable_sort(dna.begin(), dna.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.second < b.second;
        });

    // ����������ַ���
    for (const auto& p : dna) {
        cout << p.first << endl;
    }

    return 0;
}
