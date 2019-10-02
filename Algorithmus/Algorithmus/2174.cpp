#include <iostream>
#include <deque>

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

using namespace std;

struct robot {
	int x, y;
	int dir;
};

deque<robot> robots;
int **map,A,B,N,M;

void Command_L(int &dir) {
	switch (dir)
	{
	case UP:
		dir = LEFT;
		break;
	case RIGHT:
		dir = UP;
		break;
	case DOWN:
		dir = RIGHT;
		break;
	case LEFT:
		dir = DOWN;
		break;
	}
}

void Command_R(int &dir) {
	switch (dir) {
	case UP:
		dir = RIGHT;
		break;
	case RIGHT:
		dir = DOWN;
		break;
	case DOWN:
		dir = LEFT;
		break;
	case LEFT:
		dir = UP;
		break;
	}
}

void Command_F(int &x, int &y, int dir) {
	switch (dir)
	{
	case UP:
		y--;
		break;
	case RIGHT:
		x++;
		break;
	case DOWN:
		y++;
		break;
	case LEFT:
		x--;
		break;
	}
}

bool Is_Range(int x,int y) {
	if (x < 1 || x > A || y < 1 || y > B) {
		return false;
	}
	else {
		return true;
	}
}

int main() {

	cin >> A >> B;
	cin >> N >> M;

	map = new int*[B + 1];
	for (int i = 0; i <= B; i++) {
		map[i] = new int[A + 1];
		fill_n(map[i], A + 1, 0);
	}

	int ord = 1;
	for (int i = 0; i < N; i++) {
		int x, y;
		char direction;
		cin >> x >> y >> direction;

		robot rb;
		switch (direction) {
		case 'N':
			rb = { x,B + 1 - y, UP };
			break;
		case 'E':
			rb = { x,B + 1 - y, RIGHT };
			break;
		case 'S':
			rb = { x,B + 1 - y, DOWN };
			break;
		case 'W':
			rb = { x,B + 1 - y, LEFT };
			break;
		}

		map[rb.y][rb.x] = ord++;
		robots.push_back(rb);
	}

	

	for (int i = 0; i < M; i++) {
		char command;
		int rb, conn;
		cin >> rb >> command >> conn;

		for (int j = 0; j < conn; j++) {

			switch (command) {
			case 'L':
				Command_L(robots[rb - 1].dir);
				break;
			case 'R':
				Command_R(robots[rb - 1].dir);
				break;
			case 'F':
				int x, y,org_x,org_y;
				x = robots[rb - 1].x;
				y = robots[rb - 1].y;
				org_x = x;
				org_y = y;

				Command_F(x, y, robots[rb - 1].dir);

				if (!Is_Range(x, y)) {
					cout << "Robot " << rb << " crashes into the wall" << '\n';
					return 0;
				}
				else if (map[y][x] != 0) {
					cout << "Robot " << rb << " crashes into robot " << map[y][x] << '\n';
					return 0;
				}
				else {
					int temp = map[org_y][org_x];
					map[org_y][org_x] = 0;
					robots[rb - 1].x = x;
					robots[rb - 1].y = y;
					map[y][x] = temp;
				}
				break;
			}
		}

	}

	cout << "OK" << '\n';

	return 0;
}