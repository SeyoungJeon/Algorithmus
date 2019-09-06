#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

struct Shark {
	int feed;
	int size;
	int row, col;
	int move;
};

Shark s;
int N, **map, **visit;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

// 가장 가까운 먹이에서도 맨위왼쪽 먹이 위치랑 시간찾는 함수
pair<pair<int, int>, int> BFS(int **temp, Shark s) {
	deque<pair<int, int>> q;
	q.push_back({ s.row,s.col });

	int time = 0;
	int min_x = N, min_y = N;

	// 고기를 찾았는지 
	bool find = false;

	while (!q.empty()) {
		size_t q_s = q.size();

		for (size_t i = 0; i < q_s; i++) {
			pair<int, int> temp_p = q.front();
			q.pop_front();

			int row = temp_p.first;
			int col = temp_p.second;

			for (int i = 0; i < 4; i++) {
				int ny = row + dy[i];
				int nx = col + dx[i];

				if (nx < 0 || nx >= N || ny < 0 || ny >= N || visit[ny][nx] == 1)
					continue;

				visit[ny][nx] = 1;

				// 가장 왼쪽 위에 있는 물고기 좌표 찾음
				if (temp[ny][nx] < s.size && temp[ny][nx] != 0) {
					find = true;
					bool check_y = false, check_x = false;

					if (min_y > ny) {
						min_y = ny;
						min_x = nx;
					}
					else if (min_y == ny) {
						if (min_x > nx) {
							min_x = nx;
						}
					}
				}
				q.push_back({ ny,nx });
			}
		}

		time++;

		if (find) {
			break;
		}
	}

	if(find){
		return { {min_y,min_x},time };
	}
	else {
		return { {-1,-1},0 };
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	map = new int*[N];
	visit = new int*[N];
	for (int i = 0; i < N; i++) {
		map[i] = new int[N];
		visit[i] = new int[N];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				s.row = i;
				s.col = j;
				s.size = 2;
				s.feed = 0;
				s.move = 0;
			}
		}
	}

	while (true) {
		
		// 이전 상어 위치 저장
		int prev_y = s.row;
		int prev_x = s.col;

		// 방문 못하는 곳 설정	
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] > s.size) {
					visit[i][j] = 1;
				}
				else {
					visit[i][j] = 0;
				}
			}
		}

		// 물고기 위치 찾기
		pair<pair<int, int>, int> find = BFS(map, s);
		
		// 물고기 찾은게 없다면
		if (find.first.first == -1 && find.first.second == -1)
			break;

		// 상어 정보 변경
		s.move += find.second;
		s.feed += 1;
		if (s.feed == s.size && s.size < 8) {
			s.feed = 0;
			s.size += 1;
		}
		s.row = find.first.first;
		s.col = find.first.second;

		// 맵 정보 변경
		map[prev_y][prev_x] = 0;
		map[s.row][s.col] = 9;
	}

	cout << s.move << '\n';

	return 0;
}