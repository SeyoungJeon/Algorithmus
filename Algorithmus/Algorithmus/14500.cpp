#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

struct Point {
	int y, x;
};

int N, M, **map, **visit, ans = INT_MIN;
int dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };

bool MapCheck(int row, int col) {
	if (row < 0 || row >= N || col < 0 || col >= M) {
		return false;
	}
	else {
		return true;
	}
}


// ㅗ 자형 뺴고 판단
void DFS(int row, int col, int depth, int cur_sum) {
	if (depth == 4) {
		ans = max(ans, cur_sum);
		return;
	}

	
	for (int i = 0; i < 4; i++) {
		int ny = row + dir[i][0];
		int nx = col + dir[i][1];

		if (!MapCheck(ny, nx))
			continue;

		if (!visit[ny][nx]) {
			visit[row][col] = 1;
			DFS(ny, nx, depth + 1, cur_sum + map[row][col]);
			visit[row][col] = 0;
		}
	}


}

// ㅗ자형 판단
void CheckLast(int row,int col) {
	int min = INT_MAX;
	int sum = map[row][col];
	int cnt = 0;

	for (int i = 0; i < 4; i++) {
		int ny = row + dir[i][0];
		int nx = col + dir[i][1];

		if (!MapCheck(ny, nx))
			continue;

		cnt++;

		if (min > map[ny][nx])
			min = map[ny][nx];

		sum += map[ny][nx];
	}

	if (cnt == 4)
		sum -= min;

	ans = max(ans, sum);

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	map = new int*[N];
	visit = new int*[N];
	for (int i = 0; i < N; i++){
		map[i] = new int[M];
		visit[i] = new int[M];
		fill_n(visit[i], M, 0);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			DFS(i, j, 0, 0);
			CheckLast(i, j);
		}
	}

	cout << ans << '\n';
	return 0;
}