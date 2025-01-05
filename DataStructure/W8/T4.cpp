#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    unordered_set<int> ballNumbers; // �洢��ı��

    // ��ȡ m ����ı��
    for (int i = 0; i < m; ++i) {
        int num;
        cin >> num;
        ballNumbers.insert(num);
    }

    // ���� n �β�ѯ
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