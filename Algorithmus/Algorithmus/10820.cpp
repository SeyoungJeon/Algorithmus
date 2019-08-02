#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	
	string input;

	while (getline(cin,input,'\n')) {
		int arr[4] = { 0 };
		for (int j = 0; j < input.size(); j++) {
			if (input[j] >= 'a' && input[j] <= 'z') {
				arr[0] ++;
			}
			else if (input[j] >= 'A' && input[j] <= 'Z') {
				arr[1]++;
			}
			else if (input[j] == ' ') {
				arr[3]++;
			}
			else if (input[j] >= '0' && input[j] <= '9') {
				arr[2]++;
			}
		}
		for (int j = 0; j < 4; j++) {
			cout << arr[j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}