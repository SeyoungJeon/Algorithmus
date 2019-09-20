#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> v, tv;
char map[12][6];
int ans = 0, dir[4][2] = { {-1,0}, {1,0}, {0,1},{0,-1} };
bool visit[12][6];

void DFS(int row, int col, char color) {
	
	tv.push_back({ row,col });
	visit[row][col] = true;

	for (int i = 0; i < 4; i++) {
		int ny = row + dir[i][0];
		int nx = col + dir[i][1];

		if (ny < 0 || ny >= 12 || nx < 0 || nx >= 6 ||
			visit[ny][nx] || map[ny][nx] != color) {
			continue;
		}

		DFS(ny, nx, color);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> map[i][j];
		}
	}

	while(true){

		// visit �迭 �ʱ�ȭ
		for (int i = 0; i < 12; i++) {
			fill_n(visit[i], 6, false);
		}

		// 4���� �̷���� Ǫ�� ã��
		for (int i = 11; i >= 0; i--) {
			for (int j = 0; j < 6; j++) {
				if (!visit[i][j] && map[i][j] != '.') {
					DFS(i, j, map[i][j]);
					if (tv.size() >= 4) {
						for (auto k : tv) {
							v.push_back(k);
						}
					}
					tv.clear();
				}
			}
		}

		// ���� Ǫ�䰡 ���ٸ�
		if (v.size() == 0)
			break;

		// Ǫ�� ��Ʈ����
		for (auto k : v) {
			map[k.first][k.second] = '.';
		}

		v.clear();

		// ���� �� ���� Ǫ�� �̵�
		for (int i = 11; i >= 0; i--) {
			for (int j = 0; j < 6; j++) {
				if (map[i][j] != '.') {
					int y = i, x = j;
					char temp = map[y][x];
					map[y][x] = '.';
					while (map[y+1][x] == '.') {
						y++;
					}
					map[y][x] = temp;
				}
			}
		}

		// ���� ����
		ans++;
	}

	// ���� ���
	cout << ans << '\n';

	return 0;
}