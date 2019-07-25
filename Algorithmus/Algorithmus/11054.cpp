#include <iostream>
#include <limits.h>
#include <algorithm>

using namespace std;

int dp1[1001], dp2[1001], dp3[1001], a[1001], n, s;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= n; i++) {
		dp1[i] = 1;
		for (int j = 1; j < i; j++) {
			if (a[i] > a[j]) {
				dp1[i] = max(dp1[j] + 1, dp1[i]);
			}
		}
		
	}
	
	for (int i = n; i >= 1; i--) {
		dp2[i] = 1;
		for (int j = n; j > i; j--) {
			if (a[i] > a[j]) {
				dp2[i] = max(dp2[j] + 1, dp2[i]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		dp3[i] = dp1[i] + dp2[i];
		s = max(s, dp3[i]);
	}

	cout << s - 1 << '\n';

	return 0;
}