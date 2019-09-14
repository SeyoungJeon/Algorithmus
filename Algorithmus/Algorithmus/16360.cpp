#include <iostream>
#include <string>

using namespace std;

string input;
int N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> input;
		switch (input[input.size() - 1]) {
		case 'a':
			input += 's';
			break;
		case 'i':
			input += "os";
			break;
		case 'y':
			input = input.substr(0, input.size() - 1) + "ios";
			break;
		case 'l':
			input += "es";
			break;
		case 'e':
			if (input[input.size() - 2] == 'n') {
				input = input.substr(0, input.size() - 2) + "anes";
			}
			else {
				input += "us";
			}
			break;
		case 'n':
			input = input.substr(0, input.size() - 1) + "anes";
			break;
		case 'o':
			input += 's';
			break;
		case 'r':
			input += "es";
			break;
		case 't':
			input += "as";
			break;
		case 'u':
			input += 's';
			break;
		case 'v':
			input += "es";
			break;
		case 'w':
			input += "as";
			break;
		default:
			input += "us";
			break;
		}
		cout << input << '\n';
	}

	return 0;
}