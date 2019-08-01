#include <iostream>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	int a[10001] = { 0 };

	cin >> N;

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		a[temp] ++;
	}

	for (int i = 0; i < 10001; i++) {
		if (a[i] != 0) {
			for (int j = 0; j < a[i]; j++) {
				cout << i << '\n';
			}
		}
	}

	return 0;
}