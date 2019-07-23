#include <iostream>

using namespace std;

int main() {
	int N;
	int Max, Min;
	cin >> N;
	int *input = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}
	Max = input[0];
	Min = input[0];
	for (int i = 1; i < N; i++) {
		if (Max < input[i]) {
			Max = input[i];
		}
		if (Min > input[i]) {
			Min = input[i];
		}
	}
	cout << Min << " " << Max << '\n';

	return 0;
}