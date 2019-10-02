#include <iostream>
#include <vector>

#define U 0
#define R 1
#define D 2
#define L 3

using namespace std;

bool **visit, loop = false ;
int N, M, PR, PC, cur_d, ans_d , ans = -1;
char **map;

bool IsRange(int y, int x) {
	if (y < 1 || y > N || x < 1 || x > M) {
		return false;
	}
	else {
		return true;
	}
}

void DFS(int row , int col , int d, int depth) {
	
	if (!IsRange(row,col) || map[row][col] == 'C')
	{
		if (ans < depth) {
			ans_d = cur_d;
			ans = depth;
		}
		return;
	}

	if (visit[row][col]) {
		if (loop) {
			cur_d = ans_d;
		}

		switch (d) {
		case U:
			if (map[row][col] == '.') {
				if (row - 1 > 0)
				{
					if (visit[row - 1][col])
						loop = true;
				}
			}
			else if (map[row][col] == '/') {
				if (col + 1 <= M) {
					if (visit[row][col + 1])
						loop = true;
				}
			}
			else {
				if (col - 1 > 0) {
					if (visit[row][col - 1])
						loop = true;
				}
			}
			break;
		case R:
			if (map[row][col] == '.') {
				if (col + 1 <= M)
				{
					if (visit[row ][col+1])
						loop = true;
				}
			}
			else if (map[row][col] == '/') {
				if (row - 1 > 0) {
					if (visit[row-1][col])
						loop = true;
				}
			}
			else {
				if (row + 1 <= N) {
					if (visit[row+1][col])
						loop = true;
				}
			}
			break;
		case D:
			if (map[row][col] == '.') {
				if (row + 1 <= N)
				{
					if (visit[row+1][col])
						loop = true;
				}
			}
			else if (map[row][col] == '/') {
				if (col - 1 > 0) {
					if (visit[row][col-1])
						loop = true;
				}
			}
			else {
				if (col + 1 <= M) {
					if (visit[row][col+1])
						loop = true;
				}
			}
			break;
		case L:
			if (map[row][col] == '.') {
				if (col - 1 > 0)
				{
					if (visit[row][col-1])
						loop = true;
				}
			}
			else if (map[row][col] == '/') {
				if (row + 1 <= N) {
					if (visit[row+1][col])
						loop = true;
				}
			}
			else {
				if (row - 1 > 0) {
					if (visit[row-1][col])
						loop = true;
				}
			}
			break;
		}

		if (loop){
			ans_d = cur_d;
			return;
		}
		
	}

	visit[row][col] = true;

	if (map[row][col] == '.') {
		switch (d)
		{
		case U:
			DFS(row - 1, col, U, depth + 1);
			break;
		case R:
			DFS(row, col + 1, R, depth + 1);
			break;
		case D:
			DFS(row + 1, col, D, depth + 1);
			break;
		case L:
			DFS(row, col - 1, L, depth + 1);
			break;
		}
	}
	else if (map[row][col] == '/') {
		switch (d)
		{
		case U:
			DFS(row, col + 1, R, depth + 1);
			break;
		case R:
			DFS(row + 1, col , U, depth + 1);
			break;
		case D:
			DFS(row , col - 1, L, depth + 1);
			break;
		case L:
			DFS(row -1 , col, D, depth + 1);
			break;
		}
	}
	else  {
		switch (d)
		{
		case U:
			DFS(row, col - 1, L, depth + 1);
			break;
		case R:
			DFS(row + 1, col, D, depth + 1);
			break;
		case D:
			DFS(row, col + 1, R, depth + 1);
			break;
		case L:
			DFS(row - 1, col, U, depth + 1);
			break;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	map = new char*[N+1];
	visit = new bool*[N+1];
	for (int i = 0; i <= N; i++) {
		map[i] = new char[M+1];
		visit[i] = new bool[M+1];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}

	cin >> PR >> PC;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j <= N; j++) {
			fill_n(visit[j], M+1, false);
		}
		cur_d = i;
		DFS(PR, PC, i, 0);
		if (loop)
			break;
	}

	switch (ans_d) {
	case U:
		cout << 'U' << '\n';
		break;
	case R:
		cout << 'R' << '\n';
		break;
	case D:
		cout << 'D' << '\n';
		break;
	case L:
		cout << 'L' << '\n';
		break;
	}

	if (loop) {
		cout << "Voyager" << '\n';
	}
	else {
		cout << ans << '\n';
	}

	return 0;
}
