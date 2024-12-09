#include <iostream>
#include <vector>
using namespace std;

int main() {

	// 初始化 N、M
	int N = 0, M = 0;
	cin >> N >> M;

	// 创建 vector 向量作为简历
	vector<int> resumes;
	for (int i = 0; i < N; i++) {
		resumes.push_back(i + 1);
	}

	// 输入 num ，并删除指定简历
	int num = 0;
	for (int i = 0; i < M; i++) {
		cin >> num;
		resumes.erase(resumes.begin() + num - 1);
	}

	// 输出中间
	int midIndex = resumes.size() / 2;
	cout << resumes[midIndex] << endl;

	return 0;
}