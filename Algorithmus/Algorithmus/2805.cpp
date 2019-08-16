#include <iostream>
#include <vector>

#define MAX 1000000000

using namespace std;

int N, M, input, down, mid, top, max_val;
vector<int> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> input;
		v.push_back(input);
	}

	down = 0;
	top = MAX;

	while (down <= top) {
		mid = (down + top) / 2;
		
		long long result = 0;

		for (size_t i = 0; i < v.size(); i++) {
			if (v[i] > mid)
				result += v[i] - mid;
		}

		if (result < M) {
			top = mid - 1;
		}
		else {
			down = mid + 1;
			if (max_val < mid)
				max_val = mid;
		}

	}
	
	cout << max_val << '\n';
	return 0;
}