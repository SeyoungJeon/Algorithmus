#include <iostream>
#include <deque> 

#define RIGHT 0
#define UP 1
#define LEFT 2
#define DOWN 3

using namespace std;

deque<pair<int, int>> answer;
int N, ans = 0 , map[101][101] = { 0, };

void solve(int g, deque<pair<int, int>> save) {
	for (int i = 0; i < g; i++) {
		size_t ss = save.size();
		for (size_t j = ss-1; j > 0; j--) {
			int c_x = save[j].first - save[j - 1].first;
			int c_y = save[j].second - save[j - 1].second;
			save.push_back({ save[save.size() - 1].first + c_y , save[save.size() - 1].second - c_x });
		}
	}

	for (auto k : save) {
		map[k.second][k.first] = 1;
	}
}

void findAnswer() {
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			if (map[i][j] == 1 && map[i + 1][j] == 1 && map[i][j + 1] == 1 && map[i + 1][j + 1] == 1) {
				ans++;
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;

		deque<pair<int, int>> save;
		save.push_back({ x,y });
		switch (d) {
		case RIGHT:
			save.push_back({ x + 1, y });
			break;
		case UP:
			save.push_back({ x ,y - 1 });
			break;
		case LEFT:
			save.push_back({ x - 1, y });
			break;
		case DOWN:
			save.push_back({ x ,y + 1 });
			break;
		}

		solve(g, save);
	}

	findAnswer();

	cout << ans << '\n';

	return 0;
}