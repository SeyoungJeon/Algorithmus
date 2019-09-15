#include <iostream>
#include <deque>
#include <limits.h>

using namespace std;

deque<pair<int, int>> virus, temp;
int N, M, **map, ans = INT_MAX;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

// ���̷��� ����
void DFS(int depth, int cur) {
	if (depth == M - 1) {
		deque<pair<int, int>> temp2;
		int **temp_map;

		temp_map = new int*[N];
		
		for (int i = 0; i < N; i++) {
			temp_map[i] = new int[N];
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				temp_map[i][j] = map[i][j];
			}
		}

		for (size_t i = 0; i < temp.size(); i++) {
			temp_map[temp[i].first][temp[i].second] = 3;
			temp2.push_back({ temp[i].first, temp[i].second });
		}

		int time = 0;
		while (!temp2.empty()) {
			size_t temp2_size = temp2.size();
			for (size_t i = 0; i < temp2_size; i++) {
				pair<int, int> cur = temp2.front();
				temp2.pop_front();

				for (int j = 0; j < 4; j++) {
					int ny = cur.first + dy[j];
					int nx = cur.second + dx[j];
					if (ny < 0 || ny >= N || nx < 0 || nx >= N ||
						temp_map[ny][nx] == 1 || temp_map[ny][nx] == 3)
						continue;

					// ��Ȱ�� ���̷���
					if (temp_map[ny][nx] == 2) {
						bool c = false;

						// �ֺ��� �������� ������ �ִ��� �˻�
						for (int k = 0; k < 4; k++) {
							int nny = ny + dy[k];
							int nnx = nx + dx[k];

							if (nny < 0 || nny >= N || nnx < 0 || nnx >= N ||
								temp_map[nny][nnx] != 0)
								continue;

							c = true;
							break;
						}

						// �������� ������ �ִٸ�
						if (c) {
							temp_map[ny][nx] = 3;
							temp2.push_back({ ny,nx });
						}
					}
					else {
						temp_map[ny][nx] = 3;
						temp2.push_back({ ny,nx });
					}
				}
			}

			if (temp2.size() != 0)
				time++;
		}

		
		// �ʿ� ���̷����� ������ ���ϴ� ������ �ִٸ�
		bool check = true;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (temp_map[i][j] == 0) {
					check = false;
					break;
				}
			}
			if (!check)
				break;	
		}

		if (check)
			ans = ans < time ? ans : time;

		for (int i = 0; i < N; i++) {
			delete[] temp_map[i];
		}
	}

	for (size_t i = cur + 1; i < virus.size(); i++) {
		temp.push_back(virus[i]);
		DFS(depth + 1, i);
		temp.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	map = new int*[N];
	for (int i = 0; i < N; i++) {
		map[i] = new int[N];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				virus.push_back({ i,j });
			}
		}
	}

	for (size_t i = 0; i < virus.size(); i++) {
		// �ߺ� ����
		if (virus.size() - M >= i){
			temp.push_back(virus[i]);
			DFS(0, i);
			temp.pop_back();
		}
	}

	if (ans == INT_MAX)
		ans = -1;

	cout << ans << '\n';

	return 0;
}