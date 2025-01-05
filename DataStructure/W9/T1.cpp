#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> scores(n);
    vector<int> count(101, 0); // ������ΧΪ 0~100

    // ���������ͳ��ÿ�������ĳ��ִ���
    for (int i = 0; i < n; ++i) {
        cin >> scores[i];
        count[scores[i]]++;
    }

    // ȷ��������Ҫ�Ļ�����
    int required = (n + 1) / 2; // �ȼ��� ceil(n / 2.0)
    int total = 0, cutoff = 0;

    // �Ӹ߷ֵ��ͷ��ۼ��������ҵ�������
    for (int i = 100; i >= 0; --i) {
        total += count[i];
        if (total >= required) {
            cutoff = i;
            break;
        }
    }

    // �������������ߺͻ�����
    cout << cutoff << " " << total << endl;

    return 0;
}