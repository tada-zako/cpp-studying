#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
using namespace std;

#define MAX_N 1000

int main() {
	int n = 0, m = 0;
	cin >> n >> m;

	//unordered_map<int, unordered_set<int>> follows;	// ��ע��¼
	////unordered_set<string> follows;
	//vector<int> popularity(n, 0);

	//int a = 0, b = 0;
	//for (int i = 0; i < m; i++) {
	//	cin >> a >> b;

	//	if (follows[a].find(b) == follows[a].end()) {
	//		popularity[a]--;
	//		popularity[b]++;
	//		follows[a].insert(b);
	//	}
	//}

	//unordered_set<string> follows;	// ��ע��¼
	//vector<int> popularity(n, 0);

	//for (int i = 0; i < m; i++) {
	//	int a = 0, b = 0;
	//	cin >> a >> b;

	//	string follow = to_string(a) + "," + to_string(b);
	//	if (follows.find(follow) == follows.end()) {
	//		popularity[a]--;
	//		popularity[b]++;
	//		follows.insert(follow);
	//	}
	//}


	/*for (int i = 0; i < m; i++) {
		string s;
		getline(cin, s);
		istringstream iss(s);
		int a = 0, b = 0;
		iss >> a >> b;
		
		if (follows.find(s) == follows.end()) {
			popularity[a]--;
			popularity[b]++;
			follows.insert(s);
		}
	}*/


	//for (const auto i : popularity) {
	//	cout << i << endl;
	//}

	int popularity[MAX_N] = { 0 };

	// ���ڱ���Ƿ��Ѿ��������ע��ϵ
	char follows_map[MAX_N][MAX_N] = { 0 };

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		// ȷ�� a �� b ����Ч�����������Ҳ����
		if (a != b && a >= 0 && a < n && b >= 0 && b < n) {
			if (!follows_map[a][b]) { // ����Ƿ��Ѿ�����
				follows_map[a][b] = 1; // ���Ϊ�Ѵ���
				popularity[a]--;
				popularity[b]++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << popularity[i] << endl;
	}


}