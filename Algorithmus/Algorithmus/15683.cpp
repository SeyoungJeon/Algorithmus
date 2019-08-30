#include <iostream>
#include <queue>
#include <algorithm>
#include <limits.h>

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

using namespace std;

// CCTV ��ǥ
struct Point {
	int cctv;
	int y, x;
};

queue<Point> q;
int N, M, **map, c_size, ans = INT_MAX;

// ���� ����
void Move_Up(int **map, int row, int col) {
	if (row - 1 < 0)
		return;

	while (map[row - 1][col] != 6) {
		map[--row][col] = 7;
		if (row == 0)
			break;
	}
}

// ������ ����
void Move_Right(int **map, int row, int col) {
	if (col + 1 >= M)
		return;

	while (map[row][col+1] != 6) {
		map[row][++col] = 7;
		if (col == M - 1)
			break;
	}
}

// ���� ����
void Move_Left(int **map, int row, int col) {
	if (col - 1 < 0)
		return;
	while (map[row][col-1] != 6) {
		map[row][--col] = 7;
		if (col == 0)
			break;
	}
}

// �Ʒ� ����
void Move_Down(int **map, int row, int col) {
	if (row + 1 >= N)
		return;
	while (map[row+1][col] != 6) {
		map[++row][col] = 7;
		if (row == N - 1)
			break;
	}
}

// CCTV_1 ���⿡ ���� ����
void CCTV_1(int **map,int row,int col, int dir) {
	switch (dir) {
	case UP:
		Move_Up(map, row, col);
		break;
	case RIGHT:
		Move_Right(map, row, col);
		break;
	case DOWN:
		Move_Down(map, row, col);
		break;
	case LEFT:
		Move_Left(map, row, col);
		break;
	}
}

// CCTV_2 ���⿡ ���� ����
void CCTV_2(int **map, int row, int col, int dir) {
	switch (dir) {
	case UP:
		Move_Up(map, row, col);
		Move_Down(map, row, col);
		break;
	case RIGHT:
		Move_Left(map, row, col);
		Move_Right(map, row, col);
		break;
	}
}


// CCTV_3 ���⿡ ���� ����
void CCTV_3(int **map, int row, int col, int dir) {
	switch (dir) {
	case UP:
		Move_Up(map, row, col);
		Move_Right(map, row, col);
		break;
	case RIGHT:
		Move_Right(map, row, col);
		Move_Down(map, row, col);
		break;
	case DOWN:
		Move_Down(map, row, col);
		Move_Left(map, row, col);
		break;
	case LEFT:
		Move_Left(map, row, col);
		Move_Up(map, row, col);
		break;
	}
}


// CCTV_4 ���⿡ ���� ����
void CCTV_4(int **map, int row, int col, int dir) {
	switch (dir) {
	case UP:
		Move_Left(map, row, col);
		Move_Up(map, row, col);
		Move_Right(map, row, col);
		break;
	case RIGHT:
		Move_Up(map, row, col);
		Move_Right(map, row, col);
		Move_Down(map, row, col);
		break;
	case DOWN:
		Move_Right(map, row, col);
		Move_Down(map, row, col);
		Move_Left(map, row, col);
		break;
	case LEFT:
		Move_Down(map, row, col);
		Move_Left(map, row, col);
		Move_Up(map, row, col);
		break;
	}
}

// CCTV_5 ���⿡ ���� ����
void CCTV_5(int **map, int row, int col) {
	Move_Up(map, row, col);
	Move_Right(map, row, col);
	Move_Down(map, row, col);
	Move_Left(map, row, col);
}

void DFS(int **temp_map,int cnt, queue<Point> temp_q) {
	// CCTV ������ DFS ���̶� ������ 0�� ���� ���� ����
	if (c_size == cnt) {
		int zero_cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (temp_map[i][j] == 0) {
					zero_cnt++;
				}
			}
		}
		// 0�� �ּڰ� ����
		ans = min(ans, zero_cnt);
		return;
	}

	Point p = temp_q.front();
	temp_q.pop();

	int **t_m;
	t_m = new int*[N];
	for (int i = 0; i < N; i++) {
		t_m[i] = new int[M];
	}

	// �ӽ÷� �� ����
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			t_m[i][j] = temp_map[i][j];
		}
	}

	switch (p.cctv) {
	//CCTV 1 �� ���� ���Ǳ�
	case 1:
		for (int i = 0; i < 4; i++){
			CCTV_1(temp_map, p.y, p.x, i);
			DFS(temp_map, cnt + 1, temp_q);
			// �� ��������
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					temp_map[i][j] = t_m[i][j];
				}
			}
		}
		break;
	//CCTV 2 �� ���� ����
	case 2:
		for (int i = 0; i < 2; i++) {
			CCTV_2(temp_map, p.y, p.x, i);
			DFS(temp_map, cnt + 1, temp_q);
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					temp_map[i][j] = t_m[i][j];
				}
			}
		}
		break;
	case 3:
		for (int i = 0; i < 4; i++) {
			CCTV_3(temp_map, p.y, p.x, i);
			DFS(temp_map, cnt + 1, temp_q);
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					temp_map[i][j] = t_m[i][j];
				}
			}
		}
		break;
	case 4:
		for (int i = 0; i < 4; i++) {
			CCTV_4(temp_map, p.y, p.x, i);
			DFS(temp_map, cnt + 1, temp_q);
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					temp_map[i][j] = t_m[i][j];
				}
			}
		}
		break;
	//CCTV 5
	case 5:
		CCTV_5(temp_map, p.y, p.x);
		DFS(temp_map, cnt + 1, temp_q);
		break;
	}

	// �ӽ� �� �迭 ����
	for (int i = 0; i < N; i++)
		delete[] t_m[i];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	map = new int*[N];
	for (int i = 0; i < N; i++)
		map[i] = new int[M];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0 && map[i][j] != 6)
				q.push({ map[i][j],i,j });
		}
	}

	c_size = q.size();
	
	DFS(map, 0, q);

	cout << ans << '\n';

	return 0;
}