#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
	vector<int> mentionedCount(101, 0);	// 1-100 号人，每个人被提到的次数
	vector<set<int>> mentioners(101);	// 提到第 1-100 号人的所有人

	int N = 0;	// N 条微博数量
	cin >> N;
	for (int i = 0; i < N; i++) {
		int mentioner = 0, sender = 0;	// 发送者  发送数量
		cin >> mentioner >> sender;
		for (int j = 0; j < sender; j++) {
			int mentioned = 0;	// 被提及者序号
			cin >> mentioned;
			mentionedCount[mentioned]++;	// 被提到者次数加一
			mentioners[mentioned].insert(mentioner);	// 提到者序号添加
		}
	}

	// 遍历容器  寻找被提到次数最大者
	int maxCount = 0;	// 最大被提到次数
	int mostMentionedPerson = 0;	// 最大被提到者
	for (int i = 1; i <= 100; ++i) {
		if (maxCount < mentionedCount[i]) {
			maxCount = mentionedCount[i];
			mostMentionedPerson = i;
		}
	}

	// 输出结果
	cout << mostMentionedPerson << endl;

	for (const auto mentioner : mentioners[mostMentionedPerson]) {
		cout << mentioner << ' ';
	}
}