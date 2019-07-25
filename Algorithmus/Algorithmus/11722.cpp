#include <iostream>
#include <algorithm>

using namespace std;

int dp[1001], a[1001], n, t;

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		dp[i] = 1;
	}

	for (int i = n; i >= 1; i--) {
		for (int j = n; j > i; j--) {
			if (a[i] > a[j]) {
				dp[i] = max(dp[j] + 1, dp[i]);
			}
		}
		t = max(t, dp[i]);
	}

	cout << t;
	return 0;
}