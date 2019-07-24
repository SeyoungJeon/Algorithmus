#include <iostream>

using namespace std;

int main() {
	int arr[101][11];
	int N;
	cin >> N;
	for (int i = 1; i < 10; i++) {
		arr[1][i] = 1;
	}
	arr[1][0] = 0;

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0)
				arr[i][j] = arr[i - 1][j + 1];
			else if (j == 9)
				arr[i][j] = arr[i - 1][j - 1];
			else
				arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j + 1]) % 1000000000;
		}
	}

	int total = 0;
	for (int i = 0; i < 10; i++) {
		total += arr[N][i];
	}
	cout << total;
	return 0;
}