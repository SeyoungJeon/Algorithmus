#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	vector<pair<int, int>> age(N);
	vector<char[100]> name(N);

	for (int i = 0; i < N; i++) {
		scanf("%d %s", &age[i].first, name[i]);
		age[i].second = i;
	}

	sort(age.begin(), age.end());

	for (int i = 0; i < N; i++) {
		printf("%d %s\n", age[i].first, name[age[i].second]);
	}

	return 0;
}