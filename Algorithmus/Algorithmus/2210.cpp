#include <iostream>
#include <string>
#include <set>

using namespace std;

string map[5][5];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
set<string> p;

void DFS(int row, int col, int depth, string s) {
	if (depth == 6) {
		p.insert(s);	
		return;
	}

	for (int i = 0; i < 4; i++) {
		int ny = row + dy[i];
		int nx = col + dx[i];

		if (ny < 0 || ny >= 5 || nx < 0 || nx >= 5)
			continue;

		DFS(ny, nx, depth + 1, s + map[row][col]);
	}
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			DFS(i, j,0, "");
		}
	}

	cout << p.size() << '\n';
	return 0;
}
