#include <iostream>
#include <deque>
#include <algorithm>
#include <limits.h>

using namespace std;

deque<pair<int, int>> house,chicken,temp;
int N, M, ans = INT_MAX;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

//모든 치킨 거리 구하기
int Min_Chicken_Road(deque<pair<int,int>> chicken) {
	int total = 0;

	//집 마다 선택된 치킨 집 최소 거리 구하기
	for (auto h : house) {
		int min_val = INT_MAX;
		for (auto c : chicken) {
			int y_val = h.first > c.first ? h.first - c.first : c.first - h.first;
			int x_val = h.second > c.second ? h.second - c.second : c.second - h.second;
			min_val = min(min_val, x_val + y_val);
		}
		// 각 집마다의 치킨 최소 거리 더하기
		total += min_val;
	}
	return total;
}

void DFS(int depth,int k) {
	//선택된 치킨 M개일 때 모든 치킨 거리 구하기
	if (depth == M){
		ans = min(ans, Min_Chicken_Road(temp));
		return;
	}

	for (size_t i = k; i < chicken.size(); i++) {
		//선택한 치킨 집 넣기
		temp.push_back({ chicken[i].first,chicken[i].second });
		DFS(depth + 1, i+1);
		temp.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int input;
			cin >> input;
			if (input == 1) {
				house.push_back({i, j});
			}
			else if (input == 2) {
				chicken.push_back({ i,j });
			}
		}
	}

	DFS(0, 0);

	cout << ans << '\n';

	return 0;
}