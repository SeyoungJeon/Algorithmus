#include <iostream>
#include <deque>
#include <set>

using namespace std;

set<pair<int, int>> temp;
deque<pair<int, int>> enemy;
deque<int> g;
int N, M, D, **map, **temp_map, ans = 0;

// �ּ� �Ÿ� ���
int Min_D(int g_y, int g_x, int e_y, int e_x) {
	int dif_y = g_y > e_y ? g_y - e_y : e_y - g_y;
	int dif_x = g_x > e_x ? g_x - e_x : e_x - g_x;
	return dif_y + dif_x;
}

// ���� ���̱�
void Kill() {
	int total_kill = 0;

	// �� ����
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			temp_map[i][j] = map[i][j];
		}
	}
	
	// �� ó�� ��ġ ����
	deque<pair<int, int>> temp_enemy(enemy);

	while (true) {
		
		// �ü��鿡�� ���� ����� �� ã��
		for (auto k : g) {
			int min_y = N, min_x = M;
			int temp_min_d = 11;
			for (auto l : temp_enemy) {
				int temp = Min_D(N, k, l.first, l.second);
				
				// �Ÿ��� D���� ũ�� �ǳʶٱ�
				if (temp > D)
					continue;

				// ���� ����� ��ġ ã��
				if (temp_min_d > temp) {
					min_y = l.first;
					min_x = l.second;
					temp_min_d = temp;
				}
				// ���� ������ ���� ��� ���� ��� ���� ���� ��ġ ã��
				else if (temp_min_d == temp) {
					if (min_x > l.second) {
						min_y = l.first;
						min_x = l.second;
					}
				}
			}
			
			// ���� ���� �Ÿ� �̳��� ���� ���� ���
			if (min_y == N && min_x == M)
				continue;
			
			// ���� ���� �Ÿ� �̳��� ���� ���� ��� �ߺ� �����Ͽ� ����
			temp.insert({ min_y,min_x });
			
		}

		// ���� ���� �ִ� ���
		if (temp.size() != 0) {
			for (auto a : temp) {
				temp_map[a.first][a.second] = 0;
				total_kill++;
			}
		}

		// �ӽ� ������ ����
		temp_enemy.clear();
		temp.clear();

		// �� �̵�
		for (int i = N - 1; i >= 0; i--) {
			for (int j = 0; j < M; j++) {
				// ������ ������ ������ 0
				if (i == N - 1) {
					temp_map[i][j] = 0;
				}
				//������ ���� ���� ��
				else {
					// ���� �ִ� ���
					if (temp_map[i][j] == 1) {
						temp_map[i + 1][j] = 1;
						temp_map[i][j] = 0;

						temp_enemy.push_back({ i + 1,j });
					}
				}
			}
		}

		// �ʿ� ���� �����ϴ��� Ȯ��
		bool enemy_exist = false;
		for (int i = 0; i < N; i++) {
			bool find = false;
			for (int j = 0; j < M; j++) {
				if (temp_map[i][j] == 1) {
					enemy_exist = true;
					find = true;
					break;
				}
			}
			if (find)
				break;
		}
		
		// �ʿ� ���� �������� ������
		if (!enemy_exist)
			break;
	}

	// �ִ�� ���� �� �� ����
	ans = ans > total_kill ? ans : total_kill;
}

// �ü� ��ġ
void DFS(int cur, int depth) {
	if (depth == 2) {
		Kill();
		return;
	}

	for (int i = cur + 1; i < M; i++) {
		g.push_back(i);
		DFS(i, depth + 1);
		g.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> D;

	map = new int*[N + 1];
	temp_map = new int*[N + 1];
	for (int i = 0; i <= N; i++) {
		map[i] = new int[M];
		temp_map[i] = new int[M];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1)
				enemy.push_back({ i,j });
		}
	}

	for (int i = 0; i <= M - 3; i++) {
		g.push_back(i);
		DFS(i, 0);
		g.pop_back();
	}

	cout << ans << '\n';

	return 0;
}