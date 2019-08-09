#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	long long result = 1;
	cin >> N;

	while (N > 0) {
		result *= N--;
	}
	cout << result << '\n';

	return 0;
}