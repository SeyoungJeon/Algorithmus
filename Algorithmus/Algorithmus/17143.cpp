#include <iostream>
#include <deque>
#include <algorithm>

#define UP 1
#define DOWN 2
#define RIGHT 3
#define LEFT 4

using namespace std;

struct Shark {
	int s;			// 속력
	int d;			// 방향
	int z;			// 크기
};

deque<Shark> **v;
deque < pair<int, pair<int, Shark>>> g;

int R, C, M;
long long ans = 0;

void Move_Shark(int &y, int &x, int s, int &d) {
	for (int i = 0; i < s; i++) {
		switch (d) {
		case UP:
			y -= 1;
			if (y == 0) {
				d = DOWN;
				y += 2;
			}
			break;
		case DOWN:
			y += 1;
			if (y == R + 1) {
				d = UP;
				y -= 2;
			}
			break;
		case RIGHT:
			x += 1;
			if (x == C + 1) {
				d = LEFT;
				x -= 2;
			}
			break;
		case LEFT:
			x -= 1;
			if (x == 0) {
				d = RIGHT;
				x += 2;
			}
			break;
		}
	}
}

void Solve() {
	for (int i = 1; i <= C; i++) {
		cout << "C: " << i << '\n';

		// 가장 위에 있는 상어 잡기
		for (int j = 1; j <= R; j++) {
			if (v[j][i].size() != 0) {
				ans += v[j][i][0].z;
				cout << v[j][i][0].z << '\n';
				v[j][i].clear();
				
				break;
			}
		}

		for (int j = 1; j <= R; j++) {
			for (int k = 1; k <= C; k++) {
				v[j][j].clear();
			}
		}

		//상어 이동
		size_t g_s = g.size();
		while (g_s -- > 0) {
			pair<int, pair<int, Shark>> tmp;
			tmp = g.front();

			int cur_y = tmp.first;
			int cur_x = tmp.second.first;
			Shark shark = tmp.second.second;

			Move_Shark(cur_y, cur_x, shark.s, shark.d);

			if (v[cur_y][cur_x].size() == 0) {
				v[cur_y][cur_x].push_back(shark);
				g.push_back({ cur_y,{cur_x,shark} });
			}
			else {
				if (v[cur_y][cur_x][0].z < shark.z) {
					v[cur_y][cur_x].clear();
					v[cur_y][cur_x].push_back(shark);
					for (auto k : g) {
						if (k.first == cur_y && k.second.first == cur_x) {
							k.second.second.z = shark.z;
							k.second.second.d = shark.d;
							k.second.second.s = shark.s;
						}
					}
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> R >> C >> M;

	v = new deque<Shark>*[R+1];
	for (int i = 0; i <= R; i++) {
		v[i] = new deque<Shark>[C + 1];
	}

	for (int i = 0; i < M; i++) {
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		v[r][c].push_back({s,d,z});
		g.push_back({ r,{c,{s,d,z}} });
	}

	Solve();

	cout << ans << '\n';

	return 0;
}