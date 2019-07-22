#include <iostream>
#include <string>

using namespace std;

int main() {
	string input;
	while (true) {
		getline(cin, input);
		if (input == "") 
			break;
		cout << input << endl;
	}
	return 0;
}