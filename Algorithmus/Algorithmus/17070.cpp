#include <iostream>
#include <deque>

#define G 0
#define S 1
#define D 2

using namespace std;

bool **visit;
int N, **map, ans = 0;

void DFS(int row, int col, pair<int,int> pre) {
	
	if (row == N && col == N) {
		ans++;
		return;
	}

	int dif_y = row - pre.first;
	int dif_x = col - pre.second;

	int cur_mode;
	if (dif_y == 0 && dif_x == 1) {
		cur_mode = G;
	}
	else if (dif_y == 1 && dif_x == 0) {
		cur_mode = S;
	}
	else {
		cur_mode = D;
	}

	switch (cur_mode) {
	case G:
		if (col + 1 <= N && map[row][col+1] == 0) {
			DFS(row, col + 1, { row,col });
		}
		if (col + 1 <= N && row + 1 <= N && map[row + 1][col] == 0 &&
			map[row][col + 1] == 0 && map[row + 1][col + 1] == 0) {
			DFS(row + 1, col + 1, { row,col });
		}
		break;
	case S:
		if (row + 1 <= N && map[row+1][col] == 0) {
			DFS(row+1, col, { row,col });
		}
		if (col + 1 <= N && row + 1 <= N && map[row + 1][col] == 0 &&
			map[row][col + 1] == 0 && map[row + 1][col + 1] == 0) {
			DFS(row + 1, col + 1, { row,col });
		}
		break;
	case D:
		if (col + 1 <= N && map[row][col + 1] == 0) {
			DFS(row, col + 1, { row,col });
		}
		if (row + 1 <= N && map[row + 1][col] == 0) {
			DFS(row + 1, col, { row,col });
		}
		if (col + 1 <= N && row + 1 <= N && map[row + 1][col] == 0 &&
			map[row][col + 1] == 0 && map[row + 1][col + 1] == 0) {
			DFS(row + 1, col + 1, { row,col });
		}
		break;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	map = new int*[N + 1];
	visit = new bool*[N + 1];
	for (int i = 0; i <= N; i++) {
		map[i] = new int[N + 1];
		visit[i] = new bool[N + 1];
		fill_n(visit[i], N + 1, false);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	DFS(1, 2, { 1,1 });

	cout << ans << '\n';

	return 0;
}