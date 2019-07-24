#include <iostream>

using namespace std;

int main() {
	int N,test;
	int arr[11];
	cin >> N;
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;

	for (int i = 0; i < N; i++) {
		cin >> test;
		for (int j = 4; j <= test; j++) {
			arr[j] = arr[j - 1] + arr[j - 2] + arr[j - 3];
		}
		cout << arr[test] << '\n';
	}
	return 0;
}