#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>

using namespace std;

struct tree {
	int age;
	bool live;
};

vector<tree> **v;
int N, M, K, **map, **temp, ans = 0;

int dx[8] = { -1, 1, 0, 0 , 1,-1 , -1, 1 };
int dy[8] = { 0, 0 ,-1, 1 , 1, 1 , -1 ,-1 };


bool compare(const tree &a, const tree &b) {
	if (a.age < b.age) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K;
	map = new int*[N];
	temp = new int*[N];
	v = new vector<tree>*[N];
	for (int i = 0; i < N; i++) {
		map[i] = new int[N];
		temp[i] = new int[N];
		v[i] = new vector<tree>[N];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> temp[i][j];
			map[i][j] = 5;
		}
	}

	for (int i = 0; i < M; i++) {
		int y, x, z;
		cin >> y >> x >> z;
		v[y - 1][x - 1].push_back({ z,true });
	}

	while (K-- > 0) {

		// 봄
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				sort(v[i][j].begin(), v[i][j].end(),compare);
				for (auto k : v[i][j]) {
					if (map[i][j] >= k.age) {
						map[i][j] -= k.age;
						k.age += 1;
					}
					else {
						k.live = false;
					}
				}
			}
		}

		//여름 
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				for (auto iter = v[i][j].begin(); iter != v[i][j].end();) {
					if (!(*iter).live) {
						map[i][j] += (*iter).age / 2;
						iter = v[i][j].erase(iter);
					}
					else {
						iter++;
					}
				}
			}
		}
		

		// 가을 나이 5배수일 경우 8방향에 나무 심기
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << i << ' ' << j << '\n';
				size_t s = v[i][j].size();
				for (size_t k = 0; k < s; k++) {
					if (v[i][j][k].age % 5 == 0) {
						for (int m = 0; m < 8; m++) {
							int nx = j + dx[m];
							int ny = i + dy[m];

							cout << nx << ' ' << ny << '\n';

							if (nx < 0 || nx >= N || ny < 0 || ny >= N)
								continue;

							tree nt = { 1,true };
							v[i][j].push_back(nt);
						}
					}
				}
			}
		}
		

		//겨울 양분 추가
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				map[i][j] += temp[i][j];
			}
		}

	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ans += v[i][j].size();
		}
	}
	
	cout << ans << '\n';

	return 0;
}