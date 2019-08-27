#include <iostream>
#include <queue>
#include <vector>
#include <deque>
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

using namespace std;


struct Dir {
	int x;
	char c;
};

struct Snake {
	int row, col;
};

deque<Snake> snake;
deque<Dir> dir_v;
int N, K, L, **map , ans = -1;

void DFS(int row,int col, int direction,int depth) {
	
	//뱀의 몸이랑 부딪힐 때
	for (auto k : snake) {
		if (k.row == row && k.col == col) {
			ans = depth;
			return;
		}
	}

	//맵 범위 벗어날 때
	if ((row <= 0 || row > N || col <= 0 || col > N)) {
		ans = depth;
		return;
	}

	// 맵에 사과가 있을 때
	if (map[row][col] == 1) {
		snake.push_front({ row,col });
		map[row][col] = 0;
	}
	// 맵에 사과가 없을 때
	else {
		snake.push_front({ row,col });
		snake.pop_back();
	}
	
	int temp_dir= direction;

	// 방향 전환 시 
	if (!dir_v.empty() && depth == dir_v.front().x) {
		//오른쪽
		if (dir_v.front().c == 'D') {
			switch (direction) {
			case UP:
				temp_dir = RIGHT;
				break;
			case DOWN:
				temp_dir = LEFT;
				break;
			case LEFT:
				temp_dir = UP;
				break;
			case RIGHT:
				temp_dir = DOWN;
				break;
			}
		}
		//왼쪽
		else {
			switch (direction) {
			case UP:
				temp_dir = LEFT;
				break;
			case DOWN:
				temp_dir = RIGHT;
				break;
			case LEFT:
				temp_dir = DOWN;
				break;
			case RIGHT:
				temp_dir = UP;
				break;
			}
		}
		
		dir_v.pop_front();
	}

	switch (temp_dir) {
	case UP:
		DFS(row - 1, col, temp_dir, depth + 1);
		break;
	case DOWN:
		DFS(row + 1, col, temp_dir, depth + 1);
		break;
	case LEFT:
		DFS(row , col -1, temp_dir, depth + 1);
		break;
	case RIGHT:
		DFS(row , col +1, temp_dir, depth + 1);
		break;
	}


}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	map = new int*[N + 1];
	for (int i = 0; i <= N; i++) {
		map[i] = new int[N + 1];
		fill_n(map[i], N + 1, 0);
	}

	cin >> K;

	// 사과 맵에 배치
	for (int i = 0; i < K; i++) {
		int row, col;
		cin >> row >> col;
		map[row][col] = 1;
	}

	cin >> L;

	// 방향 전환 정보 큐에 넣기
	for (int i = 0; i < L; i++) {
		char C;
		int X;
		cin >> X >> C;
		dir_v.push_back({ X,C });
	}

	snake.push_front({ 1,1 });
	DFS(1, 2, RIGHT,1);

	cout << ans << '\n';

	return 0;
}