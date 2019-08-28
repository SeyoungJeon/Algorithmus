//

#include <iostream>
#include <algorithm>

using namespace std;

int N, *T, *P, *dp;

void solve() {

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	T = new int[N];
	P = new int[N];
	dp = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> T[i] >> P[i];
		dp[i] = P[i];
	}

	//dp로 접근 dp[i]는 i번쨰날의 최대 수익
	for (int i = 1; i < N; i++) {
		for (int j = 0 ; j < i; j++) {
			if (j + T[j] <= i) {
				dp[i] = max(dp[j] + P[i], dp[i]);
			}
		}
	}

	int val = 0;

	for (int i = 0; i < N; i++) {
		if (i + T[i] < N + 1) {
			val = max(val, dp[i]);
		}
	}

	cout << val << '\n';

	return 0;
}