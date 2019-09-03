#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> v;
bool **visit;
int N, L, R, **map,ans = 0;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0, 0 ,-1, 1 };

bool Difference(int a, int b) {
	int dif = a > b ? a - b : b - a;
	if (dif >= L && dif <= R) {
		return true;
	}
	else {
		return false;
	}
}

void DFS(int prev,int row, int col) {	
	
	visit[row][col] = true;
	
	v.push_back({ row,col });

	for (int i = 0; i < 4; i++) {
		int nx = col + dx[i];
		int ny = row + dy[i];
	
		if (nx < 0 || nx >= N || ny < 0 || ny >= N || !Difference(map[row][col],map[ny][nx]))
			continue;

		if (!visit[ny][nx]) {
			DFS(map[row][col], ny, nx);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> L >> R;

	map = new int*[N];
	visit = new bool*[N];

	for (int i = 0; i < N; i++){
		map[i] = new int[N];
		visit[i] = new bool[N];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}


	while (true) {
		int **temp;
		temp = new int*[N];
		for (int i = 0; i < N; i++) {
			temp[i] = new int[N];
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++)
			{
				temp[i][j] = map[i][j];
			}
		}

		for (int i = 0; i < N; i++)
			fill_n(visit[i], N, false);

		for (int i = 0; i < N ; i++) {
			for (int j = 0; j < N ; j++) {
				if (!visit[i][j]) {
					DFS(0, i, j);
					int sum = 0;
					for (auto k : v) {
						sum += map[k.first][k.second];
					}
					int val = sum / v.size();
					for (auto k : v) {
						temp[k.first][k.second] = val;
					}
			
					v.clear();
				}
			}
		}

		bool check = false;

		// 이전 맵이랑 같은지 다른지
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++)
			{
				if (map[i][j] != temp[i][j])
					check = true;
			}
		}

		// 이전맵이랑 똑같으면 그만
		if (!check) {
			break;
		}
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++)
			{
				map[i][j] = temp[i][j];
			}
		}

		for (int i = 0; i < N; i++)
			delete[] temp[i];

		ans++;
	}

	cout << ans << '\n';

	return 0;
}