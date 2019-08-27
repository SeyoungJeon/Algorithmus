#include <iostream>
#include <queue>
#include <limits.h>
#include <algorithm>

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

using namespace std;

int N, **map, ans = INT_MIN;


void ChangeMap(int dir) {

	queue<int> q;

	switch (dir) {
	case UP:
		for (int x = 0; x < N; x++) {
			//해당 행 또는 열 값에서 0이 아닌 값을 q에 저장하고 해당 자리 map 배열을 0으로 만듦
			for (int y = 0; y < N; y++) {
				if (map[y][x] != 0) {
					q.push(map[y][x]);
					map[y][x] = 0;
				}
			}

			//해당 행 또는 열의 시작 값
			int idx = 0;

			while (!q.empty()) {
				//순서 대로 저장되어 있는 q의 값
				int block = q.front();

				q.pop();

				//해당 행이 비어있을 때
				if (map[idx][x] == 0) {
					map[idx][x] = block;
				}
				//해당 행이 비어있지는 않은데, 같은 값일 때
				else if (map[idx][x] == block) {
					//해당 값을 2배하고, 행또는 열의 값 증가
					map[idx++][x] *= 2;
				}
				//해당 행이 비어있지도 않고 값도 같지 않을 때
				else {
					//행 또는 열의 값 증가시킨 후, 값 저장
					map[++idx][x] = block;
				}
			}
		}
		break;
	case DOWN:
		for (int x = 0; x < N; x++) {
			for (int y = N - 1; y >= 0; y--) {
				if (map[y][x] != 0) {
					q.push(map[y][x]);
					map[y][x] = 0;
				}
			}

			int idx = N - 1;

			while (!q.empty()) {
				int block = q.front();
				q.pop();

				if (map[idx][x] == 0) {
					map[idx][x] = block;
				}
				else if (map[idx][x] == block) {
					map[idx--][x] *= 2;
				}
				else {
					map[--idx][x] = block;
				}
			}
		}
		break;
	case LEFT:
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				if (map[y][x] != 0) {
					q.push(map[y][x]);
					map[y][x] = 0;
				}
			}

			int idx = 0;

			while (!q.empty()) {
				int block = q.front();
				q.pop();

				if (map[y][idx] == 0) {
					map[y][idx] = block;
				}
				else if (map[y][idx] == block) {
					map[y][idx++] *= 2;
				}
				else {
					map[y][++idx] = block;
				}
			}
		}
		break;
	case RIGHT:
		for (int y = 0; y < N; y++) {
			for (int x = N - 1; x >= 0; x--) {
				if (map[y][x] != 0) {
					q.push(map[y][x]);
					map[y][x] = 0;
				}
			}

			int idx = N - 1;

			while (!q.empty()) {
				int block = q.front();
				q.pop();

				if (map[y][idx] == 0) {
					map[y][idx] = block;
				}
				else if (map[y][idx] == block) {
					map[y][idx--] *= 2;
				}
				else {
					map[y][--idx] = block;
				}
			}
		}
		break;
	}
}

int findMax() {
	int temp_max = INT_MIN;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			temp_max = max(temp_max, map[i][j]);
		}
	}
	return temp_max;
}

void DFS(int depth) {
	
	//5번 이동 시 최댓 값 찾고 종료
	if (depth == 5) {
		ans = max(ans, findMax());
		return;
	}

	int **temp_map = new int*[N];
	for (int i = 0; i < N; i++) {
		temp_map[i] = new int[N];
	}

	// map 에 대한 정보 임시 저장
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			temp_map[i][j] = map[i][j];
		}
	}


	//왼쪽,오른쪽,위쪽,아래쪽 탐색
	for (int i = 0; i < 4; i++) {
		ChangeMap(i);
		DFS(depth + 1);
		
		//map에 대한 정보 복원
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				map[i][j] = temp_map[i][j];
			}
		}
	}

	for (int i = 0; i < N; i++)
		delete[] temp_map[i];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	map = new int*[N];
	for (int i = 0; i < N; i++)
		map[i] = new int[N];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			ans = max(ans, map[i][j]);
		}
	}

	DFS(0);

	cout << ans << '\n';

	for (int i = 0; i < N; i++) {
		delete[] map[i];
	}

	return 0;
}