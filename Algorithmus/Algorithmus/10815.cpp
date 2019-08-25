#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v1, v2;
int N, M,input;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> input;
		v1.push_back(input);
	}

	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> input;
		v2.push_back(input);
	}

	sort(v1.begin(), v1.end());

	while (left <= right) {
		
	}
	return 0;
}