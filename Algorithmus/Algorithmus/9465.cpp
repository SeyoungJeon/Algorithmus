#include <iostream>
#include <algorithm>

using namespace std;

int dp[2][100001], arr[2][100001], t, n;

int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		for (int j = 1; j <= n; j++) {
			cin >> arr[0][j];
		}
		for (int j = 1; j <= n; j++) {
			cin >> arr[1][j];
		}
		
		dp[0][1] = arr[0][1];
		dp[1][1] = arr[1][1];

		for (int j = 2; j <= n; j++) {
			dp[0][j] = arr[0][j] + max(dp[1][j - 1], dp[1][j - 2]);
			dp[1][j] = arr[1][j] + max(dp[0][j - 1], dp[0][j - 2]);
		}

		cout << max(dp[0][n], dp[1][n]) << '\n';

	}

	return 0;
}