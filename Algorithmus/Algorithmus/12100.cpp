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
			//�ش� �� �Ǵ� �� ������ 0�� �ƴ� ���� q�� �����ϰ� �ش� �ڸ� map �迭�� 0���� ����
			for (int y = 0; y < N; y++) {
				if (map[y][x] != 0) {
					q.push(map[y][x]);
					map[y][x] = 0;
				}
			}

			//�ش� �� �Ǵ� ���� ���� ��
			int idx = 0;

			while (!q.empty()) {
				//���� ��� ����Ǿ� �ִ� q�� ��
				int block = q.front();

				q.pop();

				//�ش� ���� ������� ��
				if (map[idx][x] == 0) {
					map[idx][x] = block;
				}
				//�ش� ���� ��������� ������, ���� ���� ��
				else if (map[idx][x] == block) {
					//�ش� ���� 2���ϰ�, ��Ǵ� ���� �� ����
					map[idx++][x] *= 2;
				}
				//�ش� ���� ��������� �ʰ� ���� ���� ���� ��
				else {
					//�� �Ǵ� ���� �� ������Ų ��, �� ����
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
	
	//5�� �̵� �� �ִ� �� ã�� ����
	if (depth == 5) {
		ans = max(ans, findMax());
		return;
	}

	int **temp_map = new int*[N];
	for (int i = 0; i < N; i++) {
		temp_map[i] = new int[N];
	}

	// map �� ���� ���� �ӽ� ����
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			temp_map[i][j] = map[i][j];
		}
	}


	//����,������,����,�Ʒ��� Ž��
	for (int i = 0; i < 4; i++) {
		ChangeMap(i);
		DFS(depth + 1);
		
		//map�� ���� ���� ����
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