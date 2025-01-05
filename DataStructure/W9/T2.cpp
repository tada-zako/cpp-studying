#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
    int N, K;
    cin >> N;

    vector<int> scores(N);
    // �������
    for (int i = 0; i < N; ++i) {
        cin >> scores[i];
    }

    cin >> K;

    // �Է����Ӹߵ�������
    sort(scores.begin(), scores.end(), greater<int>());

    // ����ǰ K �����ܷ�
    double sum = 0;
    for (int i = 0; i < K; ++i) {
        sum += scores[i];
    }

    // ����ƽ����
    double average = sum / K;

    // ���������λС��
    cout << fixed << setprecision(2) << average << endl;

    return 0;
}
