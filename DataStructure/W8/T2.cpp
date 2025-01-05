#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> numbers(n);
	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
	}

	int target;
	cin >> target;

	unordered_map<int, int> seen;

	for (int i = 0; i < n; i++) {
		int complement = target - numbers[i];

		if (seen.count(complement)) {
			cout << seen[complement] + 1 << " " << i + 1 << endl;
			return 0;
		}

		seen[numbers[i]] = i;
	}
}