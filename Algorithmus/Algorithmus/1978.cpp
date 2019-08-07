#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M=0;
	vector<int> v;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		v.push_back(input);
	}

	for (auto k : v)
	{
		bool check = false;
		for (int j = 2; j < k; j++) {
			if (k % j == 0) {
				check = true;
				break;
			}
		}
		if (!check && k != 1){
			M++;
		}
	}

	cout << M;

	return 0;
}