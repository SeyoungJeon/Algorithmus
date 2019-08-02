#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string arr[4];

	for (int i = 0; i < 4; i++) {
		cin >> arr[i];
	}

	long first = stol(arr[0]+arr[1]);
	long second = stol(arr[2] + arr[3]);

	cout << first + second << '\n';

	return 0;

}