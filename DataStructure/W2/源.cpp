#include <iostream>
using namespace std;

int main() {
    // 创建两个线性表
    int n1 = 0, n2 = 0;

    cin >> n1;
    int* p1 = new int[n1];
    for (int i = 0; i < n1; i++) {
        cin >> p1[i];
    }

    // for(int i = 0; i < n1; i++){
    //     cout << p1[i];
    // }

    cin >> n2;
    int* p2 = new int[n2];
    for (int i = 0; i < n2; i++) {
        cin >> p2[i];
    }

    // for(int i = 0; i < n2; i++){
    //     cout << p2[i];
    // }

    // 集合并集运算
    int p[100000];
    int pSize = 0;      // p集合指针，同时记录并集元素数

    // 并集操作
    int pP1 = 0, pP2 = 0;       // 集合p1、p2指针

    while (pP1 < n1 && pP2 < n2) {
        // 如果相同，写入p。不同比较元素大小，后移两集合指针
        if (p1[pP1] < p2[pP2]) {
            pP1++;
        }
        else if (p1[pP1] > p2[pP2]) {
            pP2++;
        }
        else {
            p[pSize] = p1[pP1];
            pSize++;
            pP1++;
            pP2++;
        }
    }

    // 输出新集合
    cout << pSize << endl;

    for (int i = 0; i < pSize; i++) {
        if (i == pSize - 1) {
            cout << p[i];
        }
        else {
            cout << p[i] << " ";
        }
    }

    // 释放动态分配的内存
    delete[] p1;
    delete[] p2;

    return 0;
}