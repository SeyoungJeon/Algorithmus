#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


// sort 함수에 사용할 비교함수 선언
bool compare(pair<int, int> &a, pair<int, int> &b) {
	//Y 좌표 비교
	if (b.second > a.second) {
		return true;
	}
	else if (a.second == b.second) {
		// Y좌표 같을 때 X 좌표 비교
		if (b.first > a.first) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

int main() {
	int N;
	vector<pair<int, int>> v;
	scanf("%d", &N);
	v.resize(N);

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &v[i].first, &v[i].second);
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < N; i++) {
		printf("%d %d\n", v[i].first, v[i].second);
	}

	return 0;
}