#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a%b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string input;
	int T,N;
	
	cin >> T;

	for (int i = 0; i < T; i++) {
		vector<int> v;
		long long sum = 0;
		cin >> N;
		for (int j = 0; j < N; j++) {
			int temp;
			cin >> temp;
			v.push_back(temp);
		}
		
		for (unsigned int j = 0; j < v.size(); j++) {
			for (unsigned int k = j + 1; k < v.size(); k++) {
				sum += gcd(v[j], v[k]);
			}
		}

		cout << sum << '\n';
	}

	return 0;
}