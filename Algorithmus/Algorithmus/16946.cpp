#include <iostream>
#include <string>
#include <deque>

using namespace std;

deque<pair<int,int>> q;
int N, M, **map, **temp, cnt = 2 , zero_cnt;
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

bool Is_Range(int x, int y) {
	if (x < 0 || x >= M || y < 0 || y >= N) {
		return false;
	}
	else {
		return true;
	}
}

void DFS(int row, int col) {
	temp[row][col] = cnt;
	zero_cnt++;

	for (int i = 0; i < 4; i++) {
		int ny = row + dir[i][0];
		int nx = col + dir[i][1];

		if (!Is_Range(nx, ny) || temp[ny][nx] != 0)
			continue;

		DFS(ny, nx);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	map = new int*[N];
	temp = new int*[N];
	for (int i = 0; i < N; i++) {
		map[i] = new int[M];
		temp[i] = new int[M];
	}

	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < M; j++) {
			map[i][j] = input[j] - 48;
			temp[i][j] = map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (temp[i][j] == 0) {
				zero_cnt = 0;
				DFS(i, j);

				q.push_back({ cnt,zero_cnt });

				cnt++;
			}
		}
	}

	deque<int> a;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1) {
				
				for (int k = 0; k < 4; k++) {
					bool exist = false;

					int ny = i + dir[k][0];
					int nx = j + dir[k][1];

					if (!Is_Range(nx, ny) || temp[ny][nx] == 1)
						continue;

					for (auto k : a) {
						
						if (k == temp[ny][nx]) {
							exist = true;
							break;
						}
					}


					if (exist)
						continue;

					a.push_back(temp[ny][nx]);

					map[i][j] += q[temp[ny][nx] - 2].second;

					
				}
				
				a.clear();
			}
		}
	}

	for (int i = 0; i < N; i++) {
		delete[] temp[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << (map[i][j] % 10);
		}
		cout << '\n';
	}
	
	return 0;
}