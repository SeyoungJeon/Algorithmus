#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - i - 1; j++) {
			cout << " ";
		}
		if (i == 0) {
			cout << "*";
		}
		else if (i != N - 1) {
			cout << "*";
			for (int j = 0; j < i*2-1; j++) {
				cout << " ";
			}
			cout << "*";
		}
		else {
			for (int j = 0; j < N*2-1; j++) {
				cout << "*";
			}
		}
		cout << '\n';

	}
	return 0;
}