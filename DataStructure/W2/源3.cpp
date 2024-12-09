#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	// ���⣺һ�����������У��ҳ������ظ�ֵ���������
	// ��������
	int n = 0;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	int mLen = 0;	// ��¼������г���
	int left = 0;	// ��ָ��

	unordered_set<int> seen;	// ����������Ψһ�����ж� right ֵ�Ƿ��Ѿ�������

	for (int right = 0; right < n; right++) {
		// �ж��Ҳ�ֵ�Ƿ��ظ�
		while (seen.find(a[right]) != seen.end()) {
			seen.erase(a[left]);	// ɾ�����ֵ
			left++;
		}

		// ����Ҳ�ֵ����������
		seen.insert(a[right]);

		//���� mLen
		mLen = max(mLen, right - left + 1);
	}

	cout << mLen;
}