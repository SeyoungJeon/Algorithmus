#include <iostream>
#include <queue>
#include <string>

using namespace std;

queue<pair<int, int>> q;
int **arr, **visit, N, M, cnt = 0;
string *input;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };



void BFS() {
	while (!q.empty()) {
		size_t q_size = q.size();
		//cout << "SIZE : " << q_size << '\n';
		for (size_t s = 0; s < q_size; s++) {
			int x = q.front().second;
			int y = q.front().first;

			if (x == M - 1 && y == N - 1){
				cnt++;
				return;
			}

			q.pop();

			for (int i = 0; i < 4; i++) {
				int change_x = x + dx[i];
				int change_y = y + dy[i];

				if (change_x >= 0 && change_x < M
					&& change_y >= 0 && change_y < N
					&& arr[change_y][change_x] == 1 && visit[change_y][change_x] == 0) {
					//cout << change_y << ' ' << change_x << '\n';
					visit[change_y][change_x] = 1;
					q.push({ change_y,change_x });
				}
			}
		}
		cnt++;
	
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	arr = new int*[N];
	visit = new int*[N];
	input = new string[N];

	for (int i = 0; i < N; i++) {
		arr[i] = new int[M];
		visit[i] = new int[M];
		fill_n(visit[i], M, 0);
	}

	getline(cin, input[0], '\n');

	for (int i = 0; i < N; i++) {
		getline(cin, input[i], '\n');
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			arr[i][j] = input[i][j] - '0';
		}
	}

	q.push({ 0,0 });
	visit[0][0] = 1;
	BFS();

	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}*/
	cout << cnt << '\n';
	return 0;
}