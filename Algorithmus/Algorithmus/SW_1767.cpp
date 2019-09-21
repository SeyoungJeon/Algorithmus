#include <iostream>
#include <deque>
#include <limits.h>

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

using namespace std;

deque<int> *v;
deque<int> dir_order;
deque<pair<int, int>> q,p;
int T, N, **map, **temp_map, ans, s;
int dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };

bool MoveUp(int &y, int x, int &total) {
	int k = 0; 
	while (true) {
		if (y - 1 < 0) {
			total += k;
			return true;
		}
		if (temp_map[y - 1][x] != 0) {
			return false;
		}
		else if(temp_map[y-1][x] == 0)
			temp_map[--y][x] = 2;

		k++;
	}
}

bool MoveDown(int &y, int x, int &total) {
	int k = 0;
	while (true) {
		if (y + 1 >= N) {
			total += k;
			return true;
		} 
		if (temp_map[y + 1][x] != 0) {
			return false;
		}
		else if (temp_map[y + 1][x] == 0)
			temp_map[++y][x] = 2;

		k++;
	}
}

bool MoveLeft(int y, int &x, int &total) {
	int k = 0;
	while (true) {
		if (x - 1 < 0) {
			total += k;
			return true;
		}
		if (temp_map[y][x - 1] != 0) {
			return false;
		}
		else if (temp_map[y][x-1] == 0)
			temp_map[y][--x] = 2;

		k++;
	}
}

bool MoveRight(int y, int &x, int &total) {
	int k = 0;
	while (true) {
		if (x + 1 >= N) {
			total += k;
			return true;
		}
		if(temp_map[y][x + 1] != 0){
			return false;
		}
		else if (temp_map[y][x + 1] == 0)
			temp_map[y][++x] = 2;

		k++;
	}

}

void DFS(int cur,int depth) {
	if (depth == q.size()) {
		int total = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				temp_map[i][j] = map[i][j];
			}
		}

		bool check = true;

		int t = 0;
		int temp_s = 0;
		
		for (auto k : dir_order) {
			pair<int, int> temp = q[t];
			t++;
			int y = temp.first, x = temp.second;
			
			switch (k) {
			case UP:
				check = MoveUp(y, x, total);
				break;
			case DOWN:
				check = MoveDown(y, x, total);
				break;
			case LEFT:
				check = MoveLeft(y, x, total);
				break;
			case RIGHT:
				check = MoveRight(y, x, total);
				break;
			}

			if (check) {
				temp_s++;
			}
		}

		if (temp_s == q.size()){
			s = temp_s;
			ans = ans < total ? ans : total;
		}
		
		return;
	}

	
	for (int i = 0; i < v[cur].size(); i++) {
		dir_order.push_back(v[cur][i]);
		DFS(cur + 1, depth + 1);
		dir_order.pop_back();
	}

	if (v[cur].size() == 0) {
		dir_order.push_back(-1);
		DFS(cur + 1, depth + 1);
		dir_order.pop_back();
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;

	for (int l = 0; l < T; l++) {
		ans = INT_MAX;
		cin >> N;
		map = new int*[N];
		temp_map = new int*[N];
		for (int i = 0; i < N; i++) {
			map[i] = new int[N];
			temp_map[i] = new int[N];
		}

		s = -1;
		int t = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];

				if (map[i][j] == 1) {
					if (i == 0 || i == N - 1 || j == 0 || j == N - 1) {
						p.push_back({ i,j });
					}
					else {
						q.push_back({ i,j });
						t++;
					}
				}
			}
		}

		v = new deque<int>[t];
		for (int i = 0; i < q.size(); i++) {
			pair<int, int> temp1 = q[i];

			bool move_up = true;
			bool move_down = true;
			bool move_left = true;
			bool move_right = true;
			for (int j = 0; j < q.size(); j++) {
				if (i == j) {
					continue;
				}

				pair<int, int> temp2 = q[j];
				if (temp1.first == temp2.first) {
					if (temp1.second < temp2.second) {
						move_right = false;
					}
					else {
						move_left = false;
					}
				}
				else if (temp1.second == temp2.second) {
					if (temp1.first < temp2.first) {
						move_down = false;
					}
					else {
						move_up = false;
					}
				}
			}

			for (int j = 0; j < p.size(); j++) {
				pair<int, int> temp2 = p[j];
				if (temp1.first == temp2.first) {
					if (temp1.second < temp2.second) {
						move_right = false;
					}
					else {
						move_left = false;
					}
				}
				else if (temp1.second == temp2.second) {
					if (temp1.first < temp2.first) {
						move_down = false;
					}
					else {
						move_up = false;
					}
				}
			}

			if (move_up)
				v[i].push_back(UP);
			if (move_down)
				v[i].push_back(DOWN);
			if (move_left)
				v[i].push_back(LEFT);
			if (move_right)
				v[i].push_back(RIGHT);
		}

		DFS(0, 0);
		
		cout << "#" << l + 1 << ' ' << ans;
		if (l != T - 1)
			cout << '\n';

		p.clear();
		q.clear();
		dir_order.clear();
		for (int i = 0; i < t; i++) {
			v[i].clear();
		}
	}
	
	return 0;
}