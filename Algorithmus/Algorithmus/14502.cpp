#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
	int y, x;
};

queue<Point> q;
vector<Point> v,temp_q;
int N, M, **map, **temp_map, **visit, ans = 0;
int dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };

bool CheckMap(int y, int x) {
	if (y >= 0 && y < N && x >= 0 && x < M) {
		return true;
	}
	else {
		return false;
	}
}

void BFS() {
	
	while (!q.empty()) {
		Point temp = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = temp.y + dir[i][0];
			int nx = temp.x + dir[i][1];

			if (!CheckMap(ny, nx))
				continue;

			if (visit[ny][nx] == 0 && temp_map[ny][nx] == 0) {
				visit[ny][nx] = 1;
				temp_map[ny][nx] = 2;
				q.push({ ny,nx });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	map = new int*[N];
	temp_map = new int*[N];
	visit = new int*[N];

	for (int i = 0; i < N; i++) {
		map[i] = new int[M];
		temp_map[i] = new int[M];
		visit[i] = new int[M];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2){
				temp_q.push_back({ i,j });
				visit[i][j] = 1;
			}
			else if (map[i][j] == 0) {
				v.push_back({ i,j });
			}
		}
	}

	for (int i = 0; i < v.size() ; i++) {
		for (int j = i+1; j < v.size() ; j++) {
			for (int k = j + 1; k < v.size(); k++) {
				int cnt = 0;

				for (auto k : temp_q)
					q.push(k);

				//¸Ê º¹»ç
				for (int i = 0; i < N; i++) {
					fill_n(visit[i], M, 0);
					for (int j = 0; j < M; j++) {
						temp_map[i][j] = map[i][j];
					}
				}

				temp_map[v[i].y][v[i].x] = 1;
				temp_map[v[j].y][v[j].x] = 1;
				temp_map[v[k].y][v[k].x] = 1;

				BFS();

				for (int i = 0; i < N; i++) {
					for (int j = 0; j < M; j++) {
						if (temp_map[i][j] == 0)
							cnt++;
					}
				}
			
				ans = max(ans, cnt);
			}
		}
	}

	cout << ans << '\n';

	return 0;
}