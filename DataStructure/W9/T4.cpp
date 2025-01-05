#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// ���岡����Ϣ�Ľṹ��
struct Patient {
    string id;    // ����ID
    int age;      // ��������
    int order;    // �Ǽ�˳��
};

int main() {
    int n;
    cin >> n; // ���벡����

    vector<Patient> elderly;  // �������б�
    vector<Patient> nonElderly; // ���������б�

    // ��ȡ������Ϣ
    for (int i = 0; i < n; ++i) {
        string id;
        int age;
        cin >> id >> age;
        if (age >= 60) {
            elderly.push_back({ id, age, i });
        }
        else {
            nonElderly.push_back({ id, age, i });
        }
    }

    // ���������б�����
    sort(elderly.begin(), elderly.end(), [](const Patient& a, const Patient& b) {
        if (a.age != b.age) {
            return a.age > b.age; // �����併��
        }
        return a.order < b.order; // ���Ǽ�˳������
        });

    // ���������ID
    for (const auto& p : elderly) {
        cout << p.id << endl;
    }

    // �����������ID
    for (const auto& p : nonElderly) {
        cout << p.id << endl;
    }

    return 0;
}
