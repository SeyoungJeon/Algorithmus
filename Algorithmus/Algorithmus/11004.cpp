#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	long long input;
	vector<long long> v;
	int N,K;

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> input;
		v.push_back(input);
	}

	sort(v.begin(), v.end());

	cout << v[K-1] << '\n';

	return 0;
}