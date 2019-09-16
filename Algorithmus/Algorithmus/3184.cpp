#include <iostream>

using namespace std;

int R, C, **visit, **map, total_o = 0 , total_v = 0;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void DFS(int row, int col, int &o, int &v) {
	visit[row][col] = 1;

	if (map[row][col] == 2){
		o++;
	}
	else if (map[row][col] == 3) {
		v++;
	}

	for (int i = 0; i < 4; i++) {
		int ny = row + dy[i];
		int nx = col + dx[i];

		if (ny < 0 || ny >= R || nx < 0 || nx >= C ||
			visit[ny][nx] == 1 || map[ny][nx] == 1)
			continue;

		DFS(ny, nx,o,v);
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> R >> C;
	visit = new int*[R];
	map = new int*[R];
	for (int i = 0; i < R; i++) {
		visit[i] = new int[C];
		map[i] = new int[C];
		fill_n(visit[i], C, 0);
	}

	char input;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> input;
			if (input == '.') {
				map[i][j] = 0;
			}
			else if (input == '#') {
				map[i][j] = 1;
			}
			else if (input == 'o') {
				map[i][j] = 2;
			}
			else {
				map[i][j] = 3;
			}
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] == 1 || visit[i][j] == 1)
				continue;

			int o = 0, v = 0;
			DFS(i, j, o, v);

			if (o > v) {
				total_o += o;
			}
			else {
				total_v += v;
			}
		}
	}

	cout << total_o << ' ' << total_v << '\n';

	for (int i = 0; i < R; i++) {
		delete[] map[i];
		delete[] visit[i];
	}

	return 0;
}