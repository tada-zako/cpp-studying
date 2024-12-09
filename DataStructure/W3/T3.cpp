#include <iostream>
#include <string>
using namespace std;

int main() {
	string input;
	getline(cin, input);

	// ÅĞ¶ÏÊÇ·ñ»ØÎÄ
	int right = input.size() - 1;
	for (int i = 0; i < right + 1; i++) {

		if (i + 1 == (right + 1) / 2 || right == 0) {
			cout << "true" << endl;
			break;
		}

		if (input[i] != input[right - 1 - i]) {
			cout << "false" << endl;
			break;
		}
		
	}

}