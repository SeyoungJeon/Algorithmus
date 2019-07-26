#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

int dp[100001], a[100001], n, s = INT_MIN;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	for (int i = 1; i <= n; i++) {
		dp[i] = a[i];
		if (a[i] + dp[i-1] > a[i]) {
			dp[i] = a[i] + dp[i - 1];
		}
		s = max(s, dp[i]);
	}

	cout << s;
	return 0;
}