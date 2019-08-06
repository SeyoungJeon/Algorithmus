#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long N;
	int B,r;
	deque<int> v;

	cin >> N >> B;

	while (N / B != 0) {
		r = N % B;
		v.push_front(r);
		N /= B;
	}
	v.push_front(N);

	for (auto iter = v.begin(); iter != v.end(); iter++)
		if (*iter >= 10)
			cout << char((*iter) + 55);
		else
			cout << *iter;

	return 0;
}