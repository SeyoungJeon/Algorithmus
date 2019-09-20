#include <iostream>
#include <deque>

using namespace std;

deque<pair<int, int>> coin;
int N, M, ans = 11, dir[4][2] = { {-1,0}, {1,0},{0,1},{0,-1} };
char **map;

void DFS(int coin1_y,int coin1_x, int coin2_y, int coin2_x, int depth) {
	if (depth > 10) {
		return;
	}

	for (int i = 0; i < 4; i++) {
		int coin1_ny = coin1_y + dir[i][0];
		int coin1_nx = coin1_x + dir[i][1];
		int coin2_ny = coin2_y + dir[i][0];
		int coin2_nx = coin2_x + dir[i][1];

		if ((coin1_ny < 0 || coin1_ny >= N || coin1_nx < 0 || coin1_nx >= M) &&
			(coin2_ny < 0 || coin2_ny >= N || coin2_nx < 0 || coin2_nx >= M)){
			continue;
		}

		if ((coin1_ny < 0 || coin1_ny >= N || coin1_nx < 0 || coin1_nx >= M) ||
			(coin2_ny < 0 || coin2_ny >= N || coin2_nx < 0 || coin2_nx >= M)) {
			ans = ans > depth ? depth : ans;
			return;
		}

		if (map[coin1_ny][coin1_nx] == '#' && map[coin2_ny][coin2_nx] == '#') {
			continue;
		}

		if (map[coin1_ny][coin1_nx] == '#') {
			coin1_ny = coin1_y;
			coin1_nx = coin1_x;
		}
		else if (map[coin2_ny][coin2_nx] == '#') {
			coin2_ny = coin2_y;
			coin2_nx = coin2_x;
		}

		if (coin1_y == coin2_y && coin1_x == coin2_x) {
			continue;
		}

		DFS(coin1_ny, coin1_nx, coin2_ny, coin2_nx, depth + 1);

	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	map = new char*[N];
	for (int i = 0; i < N; i++) {
		map[i] = new char[M];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'o') {
				coin.push_back({ i,j });
			}
		}
	}
	
	DFS(coin[0].first, coin[0].second, coin[1].first, coin[1].second, 1);
	
	if (ans > 10)
		ans = -1;

	cout << ans << '\n';

	return 0;
}