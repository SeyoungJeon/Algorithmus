#include <iostream>
#include <string>

using namespace std;

int main() {
	int T;
	int A = 0, B = 0;
	cin >> T;

	string input;

	for (int i = 0; i < T; i++) {
		cin >> input;
		int pos = input.find(',');
		if (input.size() > 0) {
			A = stoi(input.substr(0, pos));
			B = stoi(input.substr(pos + 1, -1));

		}
		cout << A + B << endl;
	}
}

#include <iostream>
using namespace std;

int main()
{
	int A, B, N;
	char c;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		scanf("%d%c%d", &A, &c, &B);
		cout << A + B << '\n';
	}
}