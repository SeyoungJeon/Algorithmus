#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int arr[26];
	fill_n(arr, 26, -1);

	string input;

	cin >> input;

	for (int i = 0; i < input.size(); i++) {
		if(arr[((int)input[i]) - 97] == -1)
			arr[((int)input[i]) - 97] = i;
	}

	for (int i = 0; i < 26; i++) {
		cout << arr[i] << ' ';
	}

	cout << '\n';


	return 0;
}