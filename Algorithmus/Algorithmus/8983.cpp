#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

deque<int> sade;
deque<pair<int, int>> animal;
int M, N, L, cnt = 0;

bool IsRangeL(int x, int y, int sade) {
	return (x > sade ? x - sade + y : sade - x + y) <= L ? true : false;
}

bool compare(const pair<int, int> &a, const pair<int, int> &b) {
	if (a.first < b.first)
		return true;
	else
		return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> M >> N >> L;
	for (int i = 0; i < M; i++) {
		int input;
		cin >> input;
		sade.push_back(input);
	}

	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		animal.push_back({ x,y });
	}

	sort(sade.begin(), sade.end());
	sort(animal.begin(), animal.end(),compare);

	int sade_pos = 0;
	for (int i = 0; i < N; i++) {
		if (animal[i].second > L)
			continue;

		while (sade_pos != M - 1 && sade[sade_pos + 1] < animal[i].first) {
			sade_pos++;
		}

		if (IsRangeL(animal[i].first, animal[i].second, sade[sade_pos])) {
			cnt++;
			continue;
		}

		if (sade_pos != M - 1 && IsRangeL(animal[i].first, animal[i].second, sade[sade_pos + 1])) {
			cnt++;
		}
	}

	cout << cnt << '\n';

	return 0;
}