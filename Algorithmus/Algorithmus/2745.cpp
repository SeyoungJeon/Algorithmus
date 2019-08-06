#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string N;
	int B;
	long long sum = 0;
	vector<int> v;
	cin >> N >> B;
	for (unsigned int i = 0; i < N.size() ; i++) {
		(int)N[i] < 65 ? v.push_back((int)N[i] - 48) : v.push_back((int)N[i] - 55);
		sum += v[i] * pow(B, N.size() - 1 - i);
	}

	cout << sum << '\n';

	
	return 0;
}

/*
#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string N;
	int B;
	long long sum = 0;
	cin >> N >> B;
	for (unsigned int i = 0; i < N.size() ; i++) {
		int temp = (int)N[i]-'0';
		int result = 1;
		for (unsigned int j = i; j < N.size()-1; j++) {
			result *= B;
		}
		if (temp < 10) {
			sum += temp * result;
		}
		else {
			sum += (temp - 7) * result;
		}
	}


	cout << sum << '\n';


	return 0;
}
*/