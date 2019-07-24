#include <iostream>

using namespace std;

int main() {
	int arr[1001][10] = {0};
	int N;
	cin >> N;
	
	for (int i = 0; i < 10; i++) {
		arr[1][i] = 1;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = j; k < 10; k++) {
				arr[i][j] += arr[i - 1][k] % 10007;
			}
		}
	}

	int total = 0;
	for (int i = 0; i < 10; i++) {
		total += arr[N][i];
	}

	cout << total % 10007 << '\n';

	return 0;
}