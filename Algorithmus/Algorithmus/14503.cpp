#include <iostream>

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

using namespace std;

int N, M, d, r, c, **map, **clean, ans = 0;

bool IsClean(int row,int col) {
	if ((map[row + 1][col] == 1 || clean[row + 1][col] == 1) &&		//�� ������ ���̰ų� û������ ���	
		(map[row - 1][col] == 1 || clean[row - 1][col] == 1) &&		//�Ʒ� ������ ���̰ų� û���������
		(map[row][col + 1] == 1 || clean[row][col + 1] == 1) &&		//���� ������ ���̰ų� û���������
		(map[row][col - 1] == 1 || clean[row][col - 1] == 1)) {		//���� ������ ���̰ų� û������ ���
		return false;
	}
	else {
		return true;
	}
}

//���� ������ Ǫ�� ���
void solve() {
	while (true) {

		clean[r][c] = 1;
		
		if (!IsClean(r, c)) {
			bool check = false;
			switch (d) {
			case UP:
				if (map[r + 1][c] != 1) {
					r++;
					check = true;
				}
				break;
			case DOWN:
				if (map[r - 1][c] != 1) {
					r--;
					check = true;
				}
				break;
			case LEFT:
				if (map[r][c + 1] != 1) {
					c++;
					check = true;
				}
				break;
			case RIGHT:
				if (map[r][c - 1] != 1) {
					c--;		
					check = true;
				}
				break;
			}
			if (!check)
			{
				return;
			}
		}
		else {
			switch (d) {
			case UP:
				d = LEFT;
				if (map[r][c - 1] == 0 && clean[r][c - 1] == 0) {
					ans++;
					c--;
				}
				break;
			case RIGHT:
				d = UP;
				if (map[r - 1][c] == 0 && clean[r - 1][c] == 0) {
					ans++;
					r--;
				}
				break;
			case DOWN:
				d = RIGHT;
				if (map[r][c + 1] == 0 && clean[r][c + 1] == 0) {
					ans++;
					c++;
				}
				break;
			case LEFT:
				d = DOWN;
				if (map[r + 1][c] == 0 && clean[r + 1][c] == 0) {
					ans++;
					r++;
				}
				break;
			}
		}
	}
}

// ��ͷ� Ǫ�� ���
void DFS(int row,int col, int cur_dir) {
	if (map[row][col] == 1) {
		return;
	}
	
	int temp_dir = cur_dir;

	clean[row][col] = 1;
	
	//�� �� ��� û�� ���� ���
	if (!IsClean(row, col)) {
		switch (temp_dir) {
		case UP:
			if (map[row+1][col] != 1) {
				DFS(row + 1, col, temp_dir);
			}
			break;
		case DOWN:
			if (map[row - 1][col] != 1) {
				DFS(row - 1, col, temp_dir);
			}
			break;
		case LEFT:
			if (map[row][col+1] != 1) {
				DFS(row, col+1, temp_dir);
			}
			break;
		case RIGHT:
			if (map[row][col-1] != 1) {
				DFS(row, col-1, temp_dir);
			}
			break;
		}
	}
	//�� �� �߿� û���� ������ �ִ� ���
	else {
		switch (temp_dir) {
		case UP:
			temp_dir = LEFT;
			if (map[row][col - 1] == 0 && clean[row][col - 1] == 0) {
				DFS(row, col - 1, temp_dir);
				ans++;
			}
			else {
				DFS(row, col, temp_dir);
			}
			break;
		case RIGHT:
			temp_dir = UP;
			if (map[row - 1][col] == 0 && clean[row - 1][col] == 0) {
				DFS(row - 1, col, temp_dir);
				ans++;

			}
			else {
				DFS(row, col, temp_dir);
			}
			break;
		case DOWN:
			temp_dir = RIGHT;
			if (map[row][col + 1] == 0 && clean[row][col + 1] == 0) {
				DFS(row, col + 1, temp_dir);
				ans++;

			}
			else {
				DFS(row, col, temp_dir);
			}
			break;
		case LEFT:
			temp_dir = DOWN;
			if (map[row + 1][col] == 0 && clean[row + 1][col] == 0) {
				DFS(row + 1, col, temp_dir);
				ans++;
			}
			else {
				DFS(row, col, temp_dir);
			}
			break;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	map = new int*[N];
	clean = new int*[N];

	for (int i = 0; i < N; i++) {
		map[i] = new int[M];
		clean[i] = new int[M];
		fill_n(clean[i], M, 0);
	}

	cin >> r >> c >> d;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	ans++;
	//DFS(r, c, d);
	solve();
	cout << ans << '\n';

	return 0;
}