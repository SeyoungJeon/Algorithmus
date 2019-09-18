#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

bool **visit;
int **map, N, min_val = INT_MAX;
vector<int> v,real;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	map = new int*[N];
	visit = new bool*[N];
	for (int i = 0; i < N; i++) {
		map[i] = new int[2 * N];
		visit[i] = new bool[2 * N];
		fill_n(visit[i], 2 * N, false);
	}

	int num = 1;
	for (int i = 0; i < N; i++) {
		int first, second;
		if (i % 2 == 0) {
			for (int j = 0; j < 2 * N;) {
				cin >> first >> second;
				map[i][j++] = first;
				map[i][j++] = second;
			}
		}
		else {
			map[i][0] = 0;
			map[i][(2 * N) - 1] = 0;
			visit[i][0] = true;
			visit[i][(2 * N) - 1] = true;
			for (int j = 1; j < (2 * N) - 1;) {
				cin >> first >> second;
				map[i][j++] = first;
				map[i][j++] = second;
			}
		}
	}

	return 0;
}