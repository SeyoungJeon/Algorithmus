#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string input;
	getline(cin, input, '\n');
	
	for (int i = 0; i < input.size(); i++) {
		if (!(input[i] >= '0' && input[i] <= '9' && input[i] == ' ')) {
			if (input[i] >= 'A' && input[i] <= 'Z') {
				input[i] = (char)((((int)input[i] - 65) + 13) % 26 + 65);
			}
			else if (input[i] >= 'a' && input[i] <= 'z') {
				input[i] = (char)((((int)input[i] - 97) + 13) % 26 + 97);
			}
		}
	}

	cout << input << '\n';
	
	return 0;
}