#include <iostream>
#include <vector>
#include <algorithm>

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

	std::vector<int>::iterator iter = v.begin();

	cout << "<";
	while (v.size() != 0) {
		
		pos = (pos + K - 1)% v.size();

		iter = find(v.begin(), v.end(), v[pos]);
		
		if (v.size() != 1)
			cout << *iter << ", ";
		else
			cout << *iter;
		iter = v.erase(iter);
		
	}
	cout << ">";


	return 0;
}