#include <iostream>

using namespace std;

int **map, *cnt, N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	map = new int*[101];
	cnt = new int[N + 1];
	fill_n(cnt, N+1, 0);
	for (int i = 0; i < 101; i++) {
		map[i] = new int[101];
		fill_n(map[i], 101, 0);
	}

	int x, y, w, h;

	for (int i = 1; i <= N; i++) {
		
		cin >> x >> y >> w >> h;
		
		for (int k = x; k < x + w; k++) {
			for (int l = y; l < y + h; l++) {
				map[k][l] = i;
			}
		}
	}

	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			cnt[map[i][j]]++;
		}
	}
	
	for (int i = 0; i < 101; i++)
		delete[] map[i];

	for (int i = 1; i <= N; i++) {
		cout << cnt[i] << '\n';
	}

	delete[] cnt;
	return 0;
}