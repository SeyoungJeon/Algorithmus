#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

bool **ladder;
int N, M, H , ans = INT_MAX;

bool CheckLadder() {
	for (int i = 1; i <= N; i++) {
		int cur_col = i;
		for (int j = 1; j <= H; j++) {
			if (ladder[j][cur_col])
				cur_col += 1;
			else if (ladder[j][cur_col - 1])
				cur_col -= 1;
		}
		if (i != cur_col)
			return false;
	}
	return true;
}

void DFS(int depth,int row) {
	if (depth > 3)
		return;
	
	if (CheckLadder()) {
		ans = min(ans, depth);
		return;
	}

	for (int i = row; i <= H; i++) {
		for (int j = 1; j < N; j++) {
			if (ladder[i][j])
				continue;
			if (ladder[i][j - 1])
				continue;
			if (ladder[i][j + 1])
				continue;

			ladder[i][j] = true;
			DFS(depth + 1, i);
			ladder[i][j] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> H;

	ladder = new bool*[H + 1];
	for (int i = 0; i < H + 1; i++){
		ladder[i] = new bool[N + 1];
		fill_n(ladder[i], N + 1, false);
	}

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		ladder[a][b] = 1;
	}

	DFS(0, 1);

	if (ans > 3)
		ans = -1;

	cout << ans << '\n';

	return 0;
}