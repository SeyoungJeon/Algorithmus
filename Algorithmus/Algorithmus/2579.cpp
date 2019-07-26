#include <iostream>
#include <algorithm>

using namespace std;

int dp[301], a[301], n, s;

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	dp[1] = a[1];
	dp[2] = max(a[1] + a[2], a[2]);
	dp[3] = max(a[1] + a[3], a[2] + a[3]);

	for (int i = 4; i <= n; i++) {
		dp[i] = max(a[i - 1] + a[i] + dp[i - 3], a[i] + dp[i - 2]);
	}

	cout << dp[n];

	return 0;
}
