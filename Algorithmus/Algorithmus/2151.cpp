#include <iostream>
#include <deque>

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

using namespace std;

deque<pair<int, int>> m,d;
char **map;
int N;

void DFS(int depth,int end) {
	if (depth == end) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << map[i][j];
			}
			cout << '\n';
		}
		return;
	}

	/*int **temp;
	temp = new int*[N];
	for (int i = 0; i < N; i++)
		temp[i] = new int[N];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			temp[i][j] = map[i][j];
		}
	}*/

	for (int i = 0; i < m.size(); i++) {
		pair<int, int> mirror = m[i];

		map[mirror.first][mirror.second] = '0';
		DFS(depth + 1, end);
		map[mirror.first][mirror.second] = '1';
		DFS(depth + 1, end);

		map[mirror.first][mirror.second] = '!';
	}

	/*for (int i = 0; i < N; i++)
		delete[] temp[i];*/
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	map = new char*[N];
	for (int i = 0; i < N; i++) {
		map[i] = new char[N];
	}

	for (int i = 0; i < N; i++) {
		cin >> map[i];
		for (int j = 0; j < N; j++) {
			if (map[i][j] == '!') {
				m.push_back({ i,j });
			}
			else if (map[i][j] == '#') {
				d.push_back({ i,j });
			}
		}L
	}

	for (int i = 1; i <= m.size(); i++) {
		cout << "==========\n";
		DFS(0, i);
	}

	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << map[i][j];
		}
		cout << '\n';
	}*/

	return 0;
}