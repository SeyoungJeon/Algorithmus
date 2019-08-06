#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int A, B, X=0,Y=1;

	cin >> A >> B;

	A > B ? X = B : X = A;
	
	while (X > 0)
	{
		if (A%X == 0 && B%X == 0)
			break;
		X--;
	}
	
	Y = X * (A / X) * (B / X);

	cout << X << '\n';
	cout << Y << '\n';

	return 0;
}
