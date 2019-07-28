#include <stdio.h>

long long N, K, dp[201][201] = { 0 };

int main() {

	scanf("%lld %lld", &N, &K);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (i == 1){
				dp[i][j] = j;
			}
			else {
				for (int k = 1; k <= j; k++) {
					dp[i][j] += dp[i-1][k] % 1000000000;
				}
			}
		}
	}

	printf("%lld\n", dp[N][K] % 1000000000);

	return 0;
}