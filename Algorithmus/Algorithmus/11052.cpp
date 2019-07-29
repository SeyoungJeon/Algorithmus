#include <stdio.h>

int max(int a, int b) {
	return a > b ? a : b;
}

int p[10001], dp[1001], N;

int main() {
	scanf("%d", &N);
	p[0] = 0;
	dp[0] = 0;
	for (int i = 1; i <= N; i++) {
		scanf("%d", &p[i]);
	}
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = max(dp[i], dp[i - j] + p[j]);
		}
	}

	printf("%d", dp[N]);

	return 0;
}