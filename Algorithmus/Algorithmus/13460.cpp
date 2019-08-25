#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct Point {
	int depth;
	int rx, ry, bx, by;
};

int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int N, M, hx, hy, ans = -1;
bool visit[10][10][10][10];
string *map;
queue<Point> q;

void move(int& x, int& y, int d) {
	while (1) {
		x += dir[d][1];
		y += dir[d][0];
		if (map[y][x] == '#') {
			x -= dir[d][1];
			y -= dir[d][0];
			break;
		}
		else if (map[y][x] == 'O') {
			break;
		}
	}
}

void  BFS() {
	while (!q.empty()) {

		Point p = q.front();
		q.pop();

		if (p.depth > 10)
			break;

		if (p.rx == hx && p.ry == hy) {
			ans = p.depth;
			break;
		}

		for (int j = 0; j < 4; j++) {
			int rx = p.rx;
			int ry = p.ry;
			int bx = p.bx;
			int by = p.by;

			move(rx, ry, j);
			move(bx, by, j);

			if (bx == hx && by == hy) {
				continue;
			}

			if (rx == bx && ry == by) {
				switch (j)
				{
				case 0:
					p.ry > p.by ? ry++ : by++;
					break;
				case 1:
					p.ry > p.by ? by-- : ry--;
					break;
				case 2:
					p.rx > p.bx ? rx++ : bx++;
					break;
				case 3:
					p.rx > p.bx ? bx-- : rx--;
					break;
				}
			}

			if (!visit[rx][ry][bx][by]) {
				q.push({ p.depth + 1 ,rx,ry,bx,by });
				visit[rx][ry][bx][by] = true;
			}
		}

	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Point point;
	
	cin >> N >> M;

	map = new string[N];

	getline(cin, map[0], '\n');

	for (int i = 0; i < N; i++) {
		getline(cin, map[i], '\n');
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 'R') {
				point.rx = j;
				point.ry = i;
			}
			else if (map[i][j] == 'B') {
				point.bx = j;
				point.by = i;
			}
			else if (map[i][j] == 'O') {
				hx = j;
				hy = i;
			}
		}
	}
	point.depth = 0;
	q.push(point);
	visit[point.rx][point.ry][point.bx][point.by] = true;

	BFS();

	cout << ans << '\n';

	return 0;
}