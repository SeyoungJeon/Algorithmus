#include <iostream>
#include <algorithm>

using namespace std;

int n, total, dp[100001] = { 0 };

int main() {
	cin >> n;

	// 각 수는 1의 제곱으로 나타낼 수 있음 초기화 
	for (int i = 0; i <= n; i++) {
		dp[i] = i;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j*j <= i; j++) {
			//초기값과 제곱값을 뺸거에 항을 하나 더 추가
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}

	cout << dp[n] << '\n';

	return 0;
}