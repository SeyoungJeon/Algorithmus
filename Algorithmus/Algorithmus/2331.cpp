#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int Calc(int A, int P) {
	int result = 0;

	while (A != 0) {
		result += pow(A % 10, P);
		A /= 10;
	}

	return result;
}

int DFS(int A, int P, vector<int> num) {
	for (unsigned int i = 0; i < num.size(); i++)
	{
		if (num[i] == A){
			return i;
		}
	}

	num.push_back(A);

	return  DFS(Calc(A, P), P, num);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> num;
	
	int A, P;

	cin >> A >> P;

	cout << DFS(A, P, num) << '\n';

	return 0;
}