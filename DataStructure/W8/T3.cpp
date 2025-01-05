#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findMissNumber(vector<int>& numbers) {
	int n = numbers.size();
	for (int i = 0; i < n; i++) {
		while (numbers[i] > 0 && numbers[i] <= n && numbers[numbers[i] - 1] != numbers[i]) {
			swap(numbers[i], numbers[numbers[i] - 1]);
		}
	}

	for (int i = 0; i < n; i++) {
		if (numbers[i] != i + 1) {
			return i + 1;
		}
	}
}

int main() {
	int n;
	cin >> n;

	vector<int> numbers(n);
	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
	}

	int num = findMissNumber(numbers);

	cout << num;
}