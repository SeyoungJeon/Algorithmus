#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

vector<int> team;
int N, **map, *visit, ans = INT_MAX;

int Difference(int a, int b) {
	if (a > b) {
		return a - b;
	}
	else {
		return b - a;
	}

}

void DFS(int depth, vector<int> team, int cur_team) {
	
	team.push_back(cur_team);
	
	if (team.size() == N / 2) {
		vector<int> other_team;
		int j = 0;
		for (int i = 0; i < N; i++) {
			if (j < team.size() && team[j] == i) {
				j++;
			}
			else{
				other_team.push_back(i);
			}
		}

		int start = 0;
		int link = 0;

		for (int i = 0; i < team.size(); i++) {
			for (int j = i+1; j < team.size(); j++) {
				start += map[team[i]][team[j]];
				start += map[team[j]][team[i]];
				
				link += map[other_team[i]][other_team[j]];
				link += map[other_team[j]][other_team[i]];
			}
		}

		ans = min(ans, Difference(start, link));
		return;
	}

	for (int i = cur_team + 1; i < N; i++) {

		DFS(depth + 1, team, i);
		if (team.size() == N / 2)
			break;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	map = new int*[N];
	visit = new int[N];
	for (int i = 0; i < N; i++){
		map[i] = new int[N];
	}

	fill_n(visit, N, 0);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		DFS(0, team, i);
	}

	cout << ans << '\n';

	return 0;
}