#include <iostream>

using namespace std;

int main() {
	int T;
	int A, B;
	cin >> T;
	int *result = new int[T];

	for (int i = 0; i < T; i++) {
		cin >> A >> B;
		result[i] = A + B;
	}

	for (int i = 0; i < T; i++) {
		cout << result[i] << endl;
	}

	delete[] result;

	return 0;
}

#include <iostream>

using namespace std;

int main() {
	int T;
	int A, B;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> A >> B;
		cout << A + B << endl;
	}

	return 0;
}