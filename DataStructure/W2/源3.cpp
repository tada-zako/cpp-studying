#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	// 题意：一段连续的数列，找出不含重复值的最长子数列
	// 创建数列
	int n = 0;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	int mLen = 0;	// 记录最长子数列长度
	int left = 0;	// 左指针

	unordered_set<int> seen;	// 利用其无序、唯一性质判断 right 值是否已经计数过

	for (int right = 0; right < n; right++) {
		// 判断右侧值是否重复
		while (seen.find(a[right]) != seen.end()) {
			seen.erase(a[left]);	// 删除左侧值
			left++;
		}

		// 添加右侧值进入子序列
		seen.insert(a[right]);

		//更新 mLen
		mLen = max(mLen, right - left + 1);
	}

	cout << mLen;
}