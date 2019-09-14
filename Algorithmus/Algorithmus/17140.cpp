#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int r, c, k, A[101][101], cur_row, cur_col, time = 0;

bool compare(const pair<int, int> &a, const pair<int, int> &b) {
	// 개수가 더 많은 순
	if (a.second < b.second) {
		return true;
	}
	// 개수가 같을 때
	else if (a.second == b.second) {
		// 값 오름차순
		if (a.first < b.first) {
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


void R_Operate() {
	deque<pair<int, int>> v[101];
	int max_col = 0;
	for (int i = 1; i <= cur_row; i++) {
		int temp[101];
		fill_n(temp, 101, 0);
		for (int j = 1; j <= cur_col; j++) {
			temp[A[i][j]]++;
		}

		for (int j = 1; j <= 100; j++) {
			if (temp[j] == 0)
				continue;

			v[i].push_back({ j,temp[j] });
		}

		sort(v[i].begin(), v[i].end(), compare);
		max_col = max_col > v[i].size() * 2 ? max_col : v[i].size() * 2;
		
		fill_n(A[i], 101, 0);
		int j = 1;
		while (!v[i].empty()) {
			pair<int, int> tmp = v[i].front();
			v[i].pop_front();
			A[i][j++] = tmp.first;
			A[i][j++] = tmp.second;
		}
	}
	cur_col = max_col;
}

void C_Operate() {
	deque<pair<int, int>> v[101];
	int temp2[101][101];

	int max_row = 0;
	for (int i = 1; i <= cur_col; i++) {
		int temp[101];
		fill_n(temp, 101, 0);
		for (int j = 1; j <= cur_row; j++) {
			temp[A[j][i]]++;
		}

		for (int j = 1; j <= 100; j++) {
			if (temp[j] == 0)
				continue;

			v[i].push_back({ j,temp[j] });
		}

		sort(v[i].begin(), v[i].end(), compare);
		max_row = max_row > v[i].size() * 2 ? max_row : v[i].size() * 2;

		fill_n(temp2[i], 101, 0);
		int j = 1;
		while (!v[i].empty()) {
			pair<int, int> tmp = v[i].front();
			v[i].pop_front();
			temp2[i][j++] = tmp.first;
			temp2[i][j++] = tmp.second;
		}
	}

	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			A[j][i] = temp2[i][j];
		}
	}

	cur_row = max_row;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> r >> c >> k;

	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> A[i][j];
		}
	}

	cur_row = 3;
	cur_col = 3;

	while (true) {

		if (time > 100) {
			time = -1;
			break;
		}

		if (A[r][c] == k) {
			break;
		}

		// R 연산
		if (cur_row >= cur_col) {
			R_Operate();
		}
		// C 연산
		else {
			C_Operate();
		}

		time++;
	}

	cout << time << '\n';

	return 0;
}