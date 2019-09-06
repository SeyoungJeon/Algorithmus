#include <iostream>
#include <deque>

using namespace std;

deque <pair<int, int>> t,g;
int R, C, T, **map, **temp_map ,ans =0;
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

void Wind_Other_Time() {
	int pos_y = g[0].first;
	int pos_x = g[0].second;

	deque<int> tmp;
	for (int i = pos_x + 1; i < C; i++) {
		tmp.push_back(map[pos_y][i]);
	}
	for (int i = pos_y - 1; i >= 0; i--) {
		tmp.push_back(map[i][C - 1]);
	}
	for (int i = C - 2; i >= 0; i--) {
		tmp.push_back(map[0][i]);
	}
	for (int i = 1; i < pos_y; i++) {
		tmp.push_back(map[i][0]);
	}
	tmp.pop_back();
	map[pos_y][pos_x + 1] = 0;
	for (int i = pos_x + 2; i < C; i++) {
		map[pos_y][i] = tmp.front();
		tmp.pop_front();
	}
	for (int i = pos_y - 1; i >= 0; i--) {
		map[i][C-1] = tmp.front();
		tmp.pop_front();
	}
	for (int i = C - 2; i >= 0; i--) {
		map[0][i] = tmp.front();
		tmp.pop_front();
	}
	for (int i = 1; i < pos_y; i++) {
		map[i][0] = tmp.front();
		tmp.pop_front();
	}
}

void Wind_Time() {
	int pos_y = g[1].first;
	int pos_x = g[1].second;

	deque<int> tmp;
	for (int i = pos_x + 1; i < C; i++) {
		tmp.push_back(map[pos_y][i]);
	}
	for (int i = pos_y + 1; i < R; i++) {
		tmp.push_back(map[i][C - 1]);
	}
	for (int i = C - 2; i >= 0; i--) {
		tmp.push_back(map[R-1][i]);
	}
	for (int i = R - 2; i > pos_y; i--) {
		tmp.push_back(map[i][0]);
	}
	tmp.pop_back();
	map[pos_y][pos_x + 1] = 0;
	for (int i = pos_x + 2; i < C; i++) {
		map[pos_y][i] = tmp.front();
		tmp.pop_front();
	}
	for (int i = pos_y + 1; i < R; i++) {
		map[i][C - 1] = tmp.front();
		tmp.pop_front();
	}
	for (int i = C - 2; i >= 0; i--) {
		map[R-1][i] = tmp.front();
		tmp.pop_front();
	}
	for (int i = R - 2; i > pos_y; i--) {
		map[i][0] = tmp.front();
		tmp.pop_front();
	}
}

void BFS() {


	while (T-- > 0) {
		size_t t_size = t.size();
		
		for (int i = 0; i < R; i++)
			fill_n(temp_map[i], C, 0);

		// 미세먼지 동작
		for (size_t i = 0; i < t_size; i++) {
			pair<int,int> temp = t.front();
			int cur_y = temp.first;
			int cur_x = temp.second;

			t.pop_front();

			int cnt = 0;
			for (int j = 0; j < 4; j++) {
				int ny = cur_y + dir[j][0];
				int nx = cur_x + dir[j][1];

				// 칸이 없는 경우
				if (ny < 0 || ny >= R || nx < 0 || nx >= C){
					continue;
				}

				// 공기 청정기 일 경우
				if ((g[0].first == ny && g[0].second == nx) ||
					(g[1].first == ny && g[1].second == nx)){
					continue;
				}

				cnt++;
				temp_map[ny][nx] += (map[cur_y][cur_x] / 5);
			}
			if (map[cur_y][cur_x] -  (map[cur_y][cur_x] / 5) * cnt < 0) {
				temp_map[cur_y][cur_x] = 0;
			}
			else {
				temp_map[cur_y][cur_x] -= (map[cur_y][cur_x] / 5) * cnt;
			}
		}
		
		// 변경된 맵 정보 저장
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				map[i][j] += temp_map[i][j];
			}
		}

		//공기 청정기 동작
		Wind_Time();
		Wind_Other_Time();

		// 미세먼지 위치 저장
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (map[i][j] != -1) {
					t.push_back({ i,j });
				}
		
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> R >> C >> T;

	map = new int*[R];
	temp_map = new int*[R];
	for (int i = 0; i < R; i++) {
		map[i] = new int[C];
		temp_map[i] = new int[C];
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1) {
				g.push_back({ i, j });
			}
			else if (map[i][j] != 0) {
				t.push_back({ i,j });
			}
		}
	}

	BFS();
	
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] != 0 && map[i][j] != -1) {
				ans += map[i][j];
			}
		}
	}

	cout << ans << '\n';

	return 0;
}