#include <iostream>
#include <deque>

using namespace std;

deque<pair<int, int>> water, go;
int R, C, des_y, des_x, dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} }, **visit_go;
char **map;
bool **visit_water;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> R >> C;

	map = new char*[R];
	visit_water = new bool*[R];
	visit_go = new int*[R];
	for (int i = 0; i < R; i++) {
		map[i] = new char[C];
		visit_water[i] = new bool[C];
		visit_go[i] = new int[C];
		fill_n(visit_water[i], C, false);
		fill_n(visit_go[i], C, 0);
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'D') {
				des_y = i;
				des_x = j;
			}
			else if (map[i][j] == 'S') {
				go.push_back({ i,j });
				visit_go[i][j] = true;
			}
			else if (map[i][j] == 'X') {
				visit_water[i][j] = true;
				visit_go[i][j] = true;
			}
			else if (map[i][j] == '*') {
				water.push_back({ i,j });
				visit_water[i][j] = true;
			}
		}
	}

	while (!water.empty() || !go.empty()) {
		size_t water_size = water.size();
		for (size_t i = 0; i < water_size; i++) {
			pair<int, int> wat = water.front();
			water.pop_front();

			for (int i = 0; i < 4; i++) {
				int ny = wat.first + dir[i][0];
				int nx = wat.second + dir[i][1];

				if (ny < 0 || ny >= R || nx < 0 || nx >= C)
					continue;

				if (visit_water[ny][nx] || map[ny][nx] == 'D' ||
					map[ny][nx] == 'X')
					continue;

				visit_water[ny][nx] = true;
				water.push_back({ ny,nx });
			}
		}

		size_t go_size = go.size();
		for (size_t i = 0; i < go_size; i++) {
			pair<int, int> g = go.front();
			go.pop_front();
			
			for (int i = 0; i < 4; i++) {
				int ny = g.first + dir[i][0];
				int nx = g.second + dir[i][1];

				if (ny < 0 || ny >= R || nx < 0 || nx >= C)
					continue;

				if (visit_go[ny][nx] != 0 || visit_water[ny][nx] || map[ny][nx] == 'X')
					continue;

				visit_go[ny][nx] = visit_go[g.first][g.second] + 1;
				go.push_back({ ny,nx });
			}
		}

		if (visit_go[des_y][des_x] != 0)
			break;
	}

	if (visit_go[des_y][des_x] == 0)
		cout << "KAKTUS" << '\n';
	else
		cout << visit_go[des_y][des_x] - 1 << '\n';
	
	for (int i = 0; i < R; i++) {
		delete[] map[i], visit_go[i], visit_water[i];
	}

	return 0;
}