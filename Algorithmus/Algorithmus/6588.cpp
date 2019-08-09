#include <iostream>

using namespace std;

int arr[1000001] = { 0,1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int input;

	for (int i = 2; i <= 1000000; i++) {
		for (int j = 2; j*i <= 1000000; j++)
			arr[i*j] = 1;
	}

	while (cin >> input) {
		if (input == 0)
			break;

		for (int i = 0; i < input; i++) {
			if (arr[i] == 0 && arr[input - i] == 0){
				cout << input << " = " << i << " + " << input-i << '\n';
				break;
			}
		}
	}

	return 0;
}