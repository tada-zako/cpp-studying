#include <iostream>
#include <vector>
using namespace std;

int main() {

	// ��ʼ�� N��M
	int N = 0, M = 0;
	cin >> N >> M;

	// ���� vector ������Ϊ����
	vector<int> resumes;
	for (int i = 0; i < N; i++) {
		resumes.push_back(i + 1);
	}

	// ���� num ����ɾ��ָ������
	int num = 0;
	for (int i = 0; i < M; i++) {
		cin >> num;
		resumes.erase(resumes.begin() + num - 1);
	}

	// ����м�
	int midIndex = resumes.size() / 2;
	cout << resumes[midIndex] << endl;

	return 0;
}