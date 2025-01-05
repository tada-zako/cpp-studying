#include <iostream>
#include <unordered_set>
#include <string>
#include <algorithm>
using namespace std;

int main() {

	int n;
	cin >> n;

	unordered_set<string> seen;
	string username;

	while (n--) {
		cin >> username;

		for (char& c : username) {
			c = tolower(c);
		}

		if (seen.count(username)) {
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
			seen.insert(username);
		}
	}
}