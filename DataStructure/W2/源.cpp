#include <iostream>
using namespace std;

int main() {
    // �����������Ա�
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

    // ���ϲ�������
    int p[100000];
    int pSize = 0;      // p����ָ�룬ͬʱ��¼����Ԫ����

    // ��������
    int pP1 = 0, pP2 = 0;       // ����p1��p2ָ��

    while (pP1 < n1 && pP2 < n2) {
        // �����ͬ��д��p����ͬ�Ƚ�Ԫ�ش�С������������ָ��
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

    // ����¼���
    cout << pSize << endl;

    for (int i = 0; i < pSize; i++) {
        if (i == pSize - 1) {
            cout << p[i];
        }
        else {
            cout << p[i] << " ";
        }
    }

    // �ͷŶ�̬������ڴ�
    delete[] p1;
    delete[] p2;

    return 0;
}