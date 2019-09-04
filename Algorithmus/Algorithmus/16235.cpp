#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct tree {
	int y, x;
	int age;
	bool live;
};

vector<tree> v;
int N, M, K, **map,**temp,ans = 0;

int dx[8] = { -1, 1, 0, 0 , 1,-1 , -1, 1 };
int dy[8] = { 0, 0 ,-1, 1 , 1, 1 , -1 ,-1 };


bool compare(const tree &a ,const tree &b) {
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
	for (int i = 0; i < N; i++){
		map[i] = new int[N];
		temp[i] = new int[N];
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
		v.push_back({ y - 1,x - 1,z,true });
		
	}

	int cnt = 0;
	while (cnt < K) {

		sort(v.begin(), v.end(), compare);
		
		// 봄
		for (size_t i = 0; i < v.size(); i++) {
			if (map[v[i].y][v[i].x] - v[i].age >= 0) {
				map[v[i].y][v[i].x] -= v[i].age;
				v[i].age += 1;
			}
			else {
				v[i].live = false;
			} 
		}
		
		//여름 
		for (auto iter = v.begin(); iter != v.end();) {
			if (!(*iter).live) {
				map[(*iter).y][(*iter).x] += (*iter).age / 2;
				iter = v.erase(iter);
			}
			else {
				iter++;
			}
		}
	
		// 가을 나이 5배수일 경우 8방향에 나무 심기
		size_t s = v.size();
		for (size_t k = 0; k < s; k++) {
			if (v[k].age % 5 == 0) {
				for (int i = 0; i < 8; i++) {
					int nx = v[k].x + dx[i];
					int ny = v[k].y + dy[i];

					if (nx < 0 || nx >= N || ny < 0 || ny >= N)
						continue;

					tree nt = { ny,nx,1,true};
					v.push_back(nt);
				}
			}
		}
		
		
		//겨울 양분 추가
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				map[i][j] += temp[i][j];
			}
		}

		cnt++;
	}

	for (auto k : v) {
		if (k.live){
			ans++;
		}
	}

	cout << ans << '\n';

	return 0;
}