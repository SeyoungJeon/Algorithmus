#include <iostream>

using namespace std;

#define UP 3
#define DOWN 4
#define LEFT 2
#define RIGHT 1

int N, M, x, y, K, **map, roll[6];
int cur_y, cur_x;

void solve(int dir) {

	int temp_roll[6];
	fill_n(temp_roll, 6, 0);
	switch (dir) {
	case UP:
		cur_y--;
		break;
	case DOWN:
		cur_y++;
		break;
	case LEFT:
		cur_x--;
		break;
	case RIGHT:
		cur_x++;
		break;
	}

	// 변화된 주사위 위치가 범위를 벗어날 때
	if (cur_y < 0 || cur_y >= N || cur_x < 0 || cur_x >= M) {
		switch (dir) {
		case UP:
			cur_y++;
			break;
		case DOWN:
			cur_y--;
			break;
		case LEFT:
			cur_x++;
			break;
		case RIGHT:
			cur_x--;
			break;
		}
		return;
	}

	// 임의 주사위에 상태를 저장
	switch (dir) {
	case UP:
		temp_roll[0] = roll[4];
		temp_roll[1] = roll[0];
		temp_roll[2] = roll[2];
		temp_roll[3] = roll[3];
		temp_roll[4] = roll[5];
		temp_roll[5] = roll[1];
		break;
	case DOWN:
		temp_roll[0] = roll[1];
		temp_roll[1] = roll[5];
		temp_roll[2] = roll[2];
		temp_roll[3] = roll[3];
		temp_roll[4] = roll[0];
		temp_roll[5] = roll[4];
		break;
	case LEFT:
		temp_roll[0] = roll[2];
		temp_roll[1] = roll[1];
		temp_roll[2] = roll[5];
		temp_roll[3] = roll[0];
		temp_roll[4] = roll[4];
		temp_roll[5] = roll[3];
		break;
	case RIGHT:
		temp_roll[0] = roll[3];
		temp_roll[1] = roll[1];
		temp_roll[2] = roll[0];
		temp_roll[3] = roll[5];
		temp_roll[4] = roll[4];
		temp_roll[5] = roll[2];
		break;

	}

	//주사위에 복사하기
	for (int i = 0; i < 6; i++)
		roll[i] = temp_roll[i];

	//칸의 값이 0일 떄 주사위의 값 복사
	if (map[cur_y][cur_x] == 0) {
		map[cur_y][cur_x] = roll[5];
	}
	//칸의 값이 0이 아닐 때 주사위의 바닥면의 값 변경하고, 칸의 값 0으로 바꿈
	else {
		roll[5] = map[cur_y][cur_x];
		map[cur_y][cur_x] = 0;
	}

	cout << roll[0] << '\n';

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> x >> y >> K;

	cur_y = x;
	cur_x = y;

	map = new int*[N];
	for (int i = 0; i < N; i++)
		map[i] = new int[M];

	fill_n(roll, 6, 0);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < K; i++) {
		int input;
		cin >> input;
		solve(input);
	}


	return 0;
}