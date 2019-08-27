#include <iostream>

using namespace std;

int N, *A, B, C;
long ans;

void solve() {
	for (int i = 0; i < N; i++){
		A[i] -= B;
		if (A[i] > 0) {
			ans += A[i] / C;
			if (A[i] % C != 0) {
				ans += 1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	A = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	cin >> B >> C;

	ans = N;

	solve();

	cout << ans << '\n';

	delete[] A;

	return 0;
}