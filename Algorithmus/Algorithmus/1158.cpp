#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> v,temp;
	int N, K;
	cin >> N >> K;
	
	for (int i = 1; i <= N; i++) {
		v.push_back(i);
	}

	std::vector<int>::iterator iter = v.begin();

	while (v.size() != 0) {
		if (iter == v.end())
			iter = v.begin();
		for (int i = 0; i < K - 1; i++) {
			iter++;
			if (iter == v.end())
				iter = v.begin();
		}
		temp.push_back(*iter);
		iter = v.erase(iter);
	}

	for (int i = 0; i < N; i++) {
		if (N == 1)
			cout << "<" << temp[i] << ">";
		else if (i == 0)
			cout << "<" << temp[i] << ", ";
		else if (i == N - 1)
			cout << temp[i] << ">";
		else
			cout << temp[i] << ", ";
	}

	return 0;
}