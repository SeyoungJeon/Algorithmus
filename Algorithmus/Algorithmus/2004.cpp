#include <iostream>
#include <algorithm>

using namespace std;

pair<long long , long long> Count_2_5(long  num) {
	long long num_2 = 0, num_5 = 0;
	for (long long i = 2; i <= num; i *= 2) {
		num_2 += num / i;
	}

	for (long long i = 5; i <= num; i *= 5) {
		num_5 += num / i;
	}

	return { num_2,num_5 };
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long n, m, num_2 = 0, num_5 = 0;
	
	cin >> n >> m;

	pair<long long, long long> v1 = Count_2_5(n);
	pair<long long, long long> v2 = Count_2_5(m);
	pair<long long, long long> v3 = Count_2_5(n-m);

	num_2 = v1.first - v2.first - v3.first;
	num_5 = v1.second - v2.second - v3.second;

	cout << min(num_2, num_5);


	return 0;
}