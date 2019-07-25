#include <iostream>
#include <algorithm>

using namespace std;

int dp[1001], a[1001], n, total;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= n; i++) {
		dp[i] = a[i];
		for (int j = 1; j < i; j++) {
			// �迭 �߿� - ���� �� �ִ� �͵� ���� �� ���� 
			if (a[i] > a[j] && dp[i] < dp[j] + a[i]) {
				dp[i] = dp[j] + a[i];
			}
		}
		total = max(total, dp[i]);
	}

	cout << total;
	return 0;
}