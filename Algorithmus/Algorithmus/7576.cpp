#include <iostream>
#include <queue>

using namespace std;


queue<pair<int, int>> q;
int M, N, **arr, **visit,cnt =0;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void BFS() {
	while (!q.empty()) {
		size_t q_size = q.size();
		
		for (unsigned int i = 0; i < q_size; i++) {
			int x = q.front().second;
			int y = q.front().first;
			q.pop();
			for (int j = 0; j < 4; j++) {
				int change_x = x + dx[j];
				int change_y = y + dy[j];
				
				if (change_x >= 0 && change_x < M && change_y >= 0 && change_y < N
					&& visit[change_y][change_x] == 0 && arr[change_y][change_x] == 0) {
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

	cin >> M >> N;

	arr = new int*[N];
	visit = new int*[N];
	for (int i = 0; i < N; i++){
		arr[i] = new int[M];
		visit[i] = new int[M];
		fill_n(visit[i], M, 0);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == -1)
				visit[i][j] = -1;
		}
	}

	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}*/

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 1 && visit[i][j] == 0) {
				visit[i][j] = 1;
				q.push({ i,j });
			}
		}
	}

	BFS();

	bool check = true;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visit[i][j] == 0)
				check = false;
		}
	}

	if (check)
		cout << cnt - 1 << '\n';
	else
		cout << -1 << '\n';
	return 0;
}