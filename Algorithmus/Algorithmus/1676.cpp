#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N,Num_2=0,Num_5=0,temp1,temp2;
	
	cin >> N;

	while (N > 0) {
		temp1 = N;
		temp2 = N;
		while (temp1 % 2 == 0) {
			Num_2++;
			temp1 /= 2;
		}

		while (temp2 % 5 == 0) {
			Num_5++;
			temp2 /= 5;
		}

		N--;
	}

	cout << (Num_2 < Num_5 ? Num_2 : Num_5) << '\n';

	return 0;
}