#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
	vector<int> mentionedCount(101, 0);	// 1-100 ���ˣ�ÿ���˱��ᵽ�Ĵ���
	vector<set<int>> mentioners(101);	// �ᵽ�� 1-100 ���˵�������

	int N = 0;	// N ��΢������
	cin >> N;
	for (int i = 0; i < N; i++) {
		int mentioner = 0, sender = 0;	// ������  ��������
		cin >> mentioner >> sender;
		for (int j = 0; j < sender; j++) {
			int mentioned = 0;	// ���ἰ�����
			cin >> mentioned;
			mentionedCount[mentioned]++;	// ���ᵽ�ߴ�����һ
			mentioners[mentioned].insert(mentioner);	// �ᵽ��������
		}
	}

	// ��������  Ѱ�ұ��ᵽ���������
	int maxCount = 0;	// ����ᵽ����
	int mostMentionedPerson = 0;	// ����ᵽ��
	for (int i = 1; i <= 100; ++i) {
		if (maxCount < mentionedCount[i]) {
			maxCount = mentionedCount[i];
			mostMentionedPerson = i;
		}
	}

	// ������
	cout << mostMentionedPerson << endl;

	for (const auto mentioner : mentioners[mostMentionedPerson]) {
		cout << mentioner << ' ';
	}
}