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

	//unordered_map<int, unordered_set<int>> follows;	// 关注记录
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

	//unordered_set<string> follows;	// 关注记录
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

	// 用于标记是否已经处理过关注关系
	char follows_map[MAX_N][MAX_N] = { 0 };

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		// 确保 a 和 b 是有效的索引，并且不相等
		if (a != b && a >= 0 && a < n && b >= 0 && b < n) {
			if (!follows_map[a][b]) { // 检查是否已经存在
				follows_map[a][b] = 1; // 标记为已存在
				popularity[a]--;
				popularity[b]++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << popularity[i] << endl;
	}


}