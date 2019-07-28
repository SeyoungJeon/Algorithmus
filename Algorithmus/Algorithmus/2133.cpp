#include <iostream>
#include <algorithm>

using namespace std;

int N, dp[31];

int main() {
	cin >> N;
	dp[0] = 1;
	dp[2] = 3;
	for (int i = 4; i <= N; i++) {
		dp[i] = 0;
		if (i % 2 == 0) {
			for (int j = 1; j <= i / 2; j++) {
				if (j == 1) {
					dp[i] += dp[i - 2] * 3;
				}
				else {
					dp[i] += dp[i - (2 * j)] * 2;
				}
			} 
		}
	}

	cout << dp[N] << '\n';
	return 0;
}