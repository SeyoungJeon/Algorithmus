#include <iostream>
#include <vector>
#include <limits.h>
#include <deque>

#define ONE 1
#define TWO 2
#define THR 3

using namespace std;

int map[5][5][5],temp_map[5][5][5],temp_map2[5][5][5],t[5][5], ans = INT_MAX;
bool visit[5] = { false, };
int visit2[5][5][5];
int dir[6][3] = { {-1,0,0},{1,0,0},{0,0,1},{0,0,-1},{0,-1,0},{0,1,0} };
vector<int> order,mode;

void Rotate(int l) {
	for (int i = 0; i < 5; i++) {
		fill_n(t[i], 5, 0);
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			t[i][j] = temp_map2[l][j][4-i];
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			temp_map2[l][i][j] = t[i][j];
		}
	}
}

void Change_Mode(int l, int mode) {
	switch (mode)
	{
	case ONE:
		Rotate(l);
		break;
	case TWO:
		Rotate(l);
		Rotate(l);
		break;
	case THR:
		Rotate(l);
		Rotate(l);
		Rotate(l);
		break;
	}
}

void BFS() {
	deque<pair<int, pair<int, int>>> q;
	q.push_back({ 0,{0,0} });
	visit2[0][0][0] = 0;

	while (!q.empty()) {
		pair<int, pair<int, int>> tm = q.front();
		q.pop_front();

		for (int i = 0; i < 6; i++) {
			int nh = tm.first + dir[i][0];
			int nr = tm.second.first + dir[i][1];
			int nc = tm.second.second + dir[i][2];

			if (nh < 0 || nh >= 5 || nr < 0 || nr >= 5 || nc < 0 || nc >= 5 ||
				visit2[nh][nr][nc] != -1 || temp_map2[nh][nr][nc] == 0) {
				continue;
			}

			visit2[nh][nr][nc] = visit2[tm.first][tm.second.first][tm.second.second] + 1;
			q.push_back({ nh,{nr,nc} });
		}
	}

	if(visit2[4][4][4] >= 12)
		ans = ans < visit2[4][4][4] ? ans : visit2[4][4][4];
}

// 길 찾기
void DFS3(int h,int r, int c , int depth) {
	//cout << h << ' ' << r << ' ' << c << ' ' << depth << '\n';
	if (h == 4 && r == 4 && c == 4) {
		ans = ans > depth ? depth : ans;
		return;
	}

	for (int i = 0; i < 6; i++) {
		int nh = h + dir[i][0];
		int nr = r + dir[i][1];
		int nc = c + dir[i][2];

		if (nh < 0 || nh >= 5 || nr < 0 || nr >= 5 || nc < 0 || nc >= 5 ||
			visit2[nh][nr][nc] == 1 || temp_map2[nh][nr][nc] == 0) {
			continue;
		}

		visit2[h][r][c] = 1;
		DFS3(nh, nr, nc, depth + 1);
		visit2[h][r][c] = 0;

	}
}

// 모드 결정
void DFS2(int depth,int cur) {
	if (depth == 4) {
		
		for (int l = 0; l < 5; l++) {
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					temp_map2[l][i][j] = temp_map[l][i][j];
				}
			}
		}

		for (int l = 0; l < 5; l++) {
			Change_Mode(l, mode[l]);
		}

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				fill_n(visit2[i][j], 5, -1);
			}
		}
		cout << "============================\n";
		for (auto k : order) {
			cout << k << ' ';
		}
		cout << '\n';
		for (auto k : mode) {
			cout << k << ' ';
		}
		cout << '\n';
			
		cout << "============================\n";
		for (int l = 0; l < 5; l++) {
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					cout << temp_map2[l][i][j];
				}
				cout << '\n';
			}
			cout << '\n';
		}

		if(temp_map2[0][0][0] == 1 && temp_map2[4][4][4] == 1){
			
			BFS();
			
			
		}
			//DFS3(0, 0, 0, 0);

		
		
		if (ans == 12) {
			cout << ans << '\n';
			exit(0);
		}

		return;
	}

	for (int i = 0; i < 5; i++) {
		
		mode.push_back(i);
		DFS2(depth + 1,i);
		mode.pop_back();
	}

}


// 순서 결정
void DFS(int cur, int depth) {
	if (depth == 4) {

		for (auto k : order) {
			int l = 0;
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					temp_map[l][i][j] = map[k][i][j];
				}
			}
			l++;
		}

		// 각 층 모양 결정
		for (int i = 0; i < 5; i++) {
			mode.push_back(i);
			DFS2(0, i);
			mode.pop_back();
		}

		return;
	}


	for (int i = 0; i < 5; i++) {
		if (visit[i])
			continue;

		visit[i] = true;
		order.push_back(i);
		DFS(i, depth + 1);
		order.pop_back();
		visit[i] = false;
	}
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			for(int k = 0; k < 5; k++) {
				cin >> map[i][j][k];
				temp_map[i][j][k] = map[i][j][k];
			}
		}
	}

	//판을 자유롭게 쌓기
	for (int i = 0; i < 5; i++) {
		visit[i] = true;
		order.push_back(i);
		DFS(i, 0);
		order.pop_back();
		visit[i] = false;
	}

	if (ans == INT_MAX)
		ans = -1;

	cout << ans << '\n';

	return 0;
}