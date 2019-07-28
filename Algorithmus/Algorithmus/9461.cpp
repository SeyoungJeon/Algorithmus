#include <iostream>

using namespace std;

long long T, n, dp[101] = { 0,1,1 };

int main() {
	cin >> T;

	for (int i = 3; i <= 100; i++) {
		dp[i] = dp[i - 2] + dp[i - 3];
	}

	for (int i = 0; i < T; i++) {
		cin >> n;
		cout << dp[n] << '\n';
	}
	return 0;
}