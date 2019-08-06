#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T,A, B, X;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> A >> B;
		X = 0;
		A < B ? X = A : X = B;
		while (X > 0) {
			if (A % X == 0 && B%X == 0)
				break;
			X--;
		}
		cout << A*B/X << '\n';
	}
	
	return 0;
}

//#include<iostream>
//using namespace std;
//
//int gcd(int a, int b) {
//	if (b == 0) return a;
//	else {
//		return gcd(b, a%b);
//	}
//}
//
//int main() {
//	int g;
//	long long int l;
//	int T;
//
//	cin >> T;
//	for (int i = 0; i < T; i++) {
//		int x, y;
//		cin >> x >> y;
//		g = gcd(x, y);
//		l = x * y / g;
//		cout << l << endl;
//	}
//
//
//	return 0;
//}