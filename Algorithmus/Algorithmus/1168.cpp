#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> v;
	int N, K,pos = 0;
	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		v.push_back(i);
	}

	cout << "<";
	while (v.size() != 0) {
		
		pos = (pos + K - 1)% v.size();

		if (v.size() != 1)
			cout << v[pos] << ", ";
		else
			cout << v[pos];
		v.erase(v.begin() + pos);
		
	}
	cout << ">";

	return 0;
}