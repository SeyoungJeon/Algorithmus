#include <iostream>
#include <string>

using namespace std;

long long gcd(long long a, long long b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a%b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	long long A, B, temp_gcd;
	string word = "";
	cin >> A >> B;

	temp_gcd = gcd(A, B);

	//메모리 많이쓰고 시간 적음
	for (int i = 0; i < temp_gcd; i++) {
		word += "1";
	}

	/*	// 메모리 적게 쓰고 시간 늘어남
	for (int i=0; i< temp_gcd; i++){
		cout << 1;
	}
	*/

	cout <<word << '\n';
	
	return 0;
}