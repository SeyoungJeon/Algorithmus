#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string input;
	int arr[26] = { 0 };

	cin >> input;

	for (int i = 0; i < input.size(); i++) {
		arr[((int)input[i]) - 97]++;
	}

	for (int i = 0; i < 26; i++) {
		cout << arr[i] << " ";
	}

	cout << '\n';
	
	return 0;
}