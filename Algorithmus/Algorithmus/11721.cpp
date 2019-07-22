#include <iostream>
#include <string>

using namespace std;

int main() {
	string input;
	int N;
	cin >> input;
	while (input.size() > 10) {
		cout << input.substr(0, 10) << endl;
		input = input.substr(10, -1);
	}
	cout << input << endl;

	return 0;
}