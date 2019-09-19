#include <iostream>
#include <deque>
#include <set>

using namespace std;

set<pair<int, int>> temp;
deque<pair<int, int>> enemy;
deque<int> g;
int N, M, D, **map, **temp_map, ans = 0;

// 최소 거리 계산
int Min_D(int g_y, int g_x, int e_y, int e_x) {
	int dif_y = g_y > e_y ? g_y - e_y : e_y - g_y;
	int dif_x = g_x > e_x ? g_x - e_x : e_x - g_x;
	return dif_y + dif_x;
}

// 적들 죽이기
void Kill() {
	int total_kill = 0;

	// 맵 복사
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			temp_map[i][j] = map[i][j];
		}
	}
	
	// 적 처음 위치 복사
	deque<pair<int, int>> temp_enemy(enemy);

	while (true) {
		
		// 궁수들에게 가장 가까운 적 찾기
		for (auto k : g) {
			int min_y = N, min_x = M;
			int temp_min_d = 11;
			for (auto l : temp_enemy) {
				int temp = Min_D(N, k, l.first, l.second);
				
				// 거리가 D보다 크면 건너뛰기
				if (temp > D)
					continue;

				// 가장 가까운 위치 찾기
				if (temp_min_d > temp) {
					min_y = l.first;
					min_x = l.second;
					temp_min_d = temp;
				}
				// 가장 가까운게 여러 경우 있을 경우 가장 왼쪽 위치 찾기
				else if (temp_min_d == temp) {
					if (min_x > l.second) {
						min_y = l.first;
						min_x = l.second;
					}
				}
			}
			
			// 제한 범위 거리 이내에 적이 없을 경우
			if (min_y == N && min_x == M)
				continue;
			
			// 제한 범위 거리 이내에 적이 있을 경우 중복 제거하여 삽입
			temp.insert({ min_y,min_x });
			
		}

		// 죽일 적이 있는 경우
		if (temp.size() != 0) {
			for (auto a : temp) {
				temp_map[a.first][a.second] = 0;
				total_kill++;
			}
		}

		// 임시 데이터 삭제
		temp_enemy.clear();
		temp.clear();

		// 적 이동
		for (int i = N - 1; i >= 0; i--) {
			for (int j = 0; j < M; j++) {
				// 성으로 도달한 적들은 0
				if (i == N - 1) {
					temp_map[i][j] = 0;
				}
				//성으로 도달 못한 적
				else {
					// 적이 있는 경우
					if (temp_map[i][j] == 1) {
						temp_map[i + 1][j] = 1;
						temp_map[i][j] = 0;

						temp_enemy.push_back({ i + 1,j });
					}
				}
			}
		}

		// 맵에 적이 존재하는지 확인
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
		
		// 맵에 적이 존재하지 않으면
		if (!enemy_exist)
			break;
	}

	// 최대로 죽인 적 수 저장
	ans = ans > total_kill ? ans : total_kill;
}

// 궁수 위치
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