#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 定义病人信息的结构体
struct Patient {
    string id;    // 病人ID
    int age;      // 病人年龄
    int order;    // 登记顺序
};

int main() {
    int n;
    cin >> n; // 输入病人数

    vector<Patient> elderly;  // 老年人列表
    vector<Patient> nonElderly; // 非老年人列表

    // 读取病人信息
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

    // 对老年人列表排序
    sort(elderly.begin(), elderly.end(), [](const Patient& a, const Patient& b) {
        if (a.age != b.age) {
            return a.age > b.age; // 按年龄降序
        }
        return a.order < b.order; // 按登记顺序升序
        });

    // 输出老年人ID
    for (const auto& p : elderly) {
        cout << p.id << endl;
    }

    // 输出非老年人ID
    for (const auto& p : nonElderly) {
        cout << p.id << endl;
    }

    return 0;
}
