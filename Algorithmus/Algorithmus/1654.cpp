#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

long long K, N, input,max_val=0;
vector<long long> v;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> K >> N;

	for (int i = 0; i < K; i++) {
		cin >> input;
		v.push_back(input);
	}

	long long left, right,mid;
	left = 0;
	right = LLONG_MAX;

	while (left <= right) {
		mid = (left + right) / 2;
		long long result = 0;

		for (unsigned int i = 0; i < v.size(); i++) {
			result += v[i] / mid;
		}

		if (result < N) {
			right = mid -1;
		}
		else {
			left = mid + 1;
			if (mid > max_val)
				max_val = mid;
		}
	
	}

	cout << max_val << '\n';

	return 0;
}