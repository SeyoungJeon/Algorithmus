#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long N;
	string result = "";
	cin >> N;

	while (N != 0) {
		if (N < 0) {
			if ((N*(-1)) % 2 == 1) {
				result = "1" + result;
				N += -1;
			}
			else {
				result = to_string(N % (-2)) + result;
			}
		}
		else {
			result = to_string(N % (-2)) + result;
		}
		N /= -2;
	}
	if (result == "")
		result += "0";

	cout << result << '\n';

	return 0;
}