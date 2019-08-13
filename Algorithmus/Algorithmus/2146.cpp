#include <iostream>
#include <deque>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;
int N, **visit, bridge = INT_MAX,cnt=0;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
bool **arr;
deque<deque<pair<int, int>>> land;

int BFS(int land_Num) {
	int min = 0;

	for (int i = 0; i < N; i++) {
		fill_n(arr[i], N, 0);
	}

	while (!land[land_Num-1].empty()) {

		size_t land_Num_size = land[land_Num-1].size();

		for (size_t i = 0; i < land_Num_size; i++) {
			int x = land[land_Num-1].front().second;
			int y = land[land_Num-1].front().first;

			if (visit[y][x] != 0 && visit[y][x] != land_Num) {
				return min;
			}

			land[land_Num-1].pop_front();

			
			for (int j = 0; j < 4; j++) {
				int d_x = x + dx[j];
				int d_y = y + dy[j];

				if (d_x >= 0 && d_x < N && d_y >= 0 && d_y < N
					&& arr[d_y][d_x] == 0 && visit[d_y][d_x] != land_Num) {
					arr[d_y][d_x] = 1;
					land[land_Num-1].push_back({ d_y,d_x });
				}
			}
		}
		min++;
	}
}

void DFS(deque<pair<int,int>> *temp,int row, int col) {
	visit[row][col] = cnt;

	temp->push_back({ row,col });
	
	for (int i = 0; i < 4; i++) {
		int change_x = col + dx[i];
		int change_y = row + dy[i];
		if (change_x >= 0 && change_x < N && change_y >= 0 && change_y < N &&
			(visit[change_y][change_x] == 0 && arr[change_y][change_x] == 1)) {
			DFS(temp, change_y, change_x);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	arr = new bool*[N];
	visit = new int*[N];
	
	for (int i = 0; i < N; i++) {
		arr[i] = new bool[N];
		visit[i] = new int[N];
		fill_n(visit[i], N, 0);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 1 && visit[i][j] == 0) {
				deque<pair<int, int>> temp;
				cnt++;
				DFS(&temp, i, j);
				land.push_back(temp);
			}
		}
	}

	for (int i = 1; i <= cnt; i++) {
		int temp = BFS(i);
		bridge = min(bridge, temp) ;
	}

	cout << bridge -1 << '\n';

	return 0;
}