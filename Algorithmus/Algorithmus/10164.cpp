#include <iostream>

using namespace std;

int N, M, K;

bool Is_Range(int x, int y, int des_x, int des_y) {
	if (y < 0 || y >= des_y || x < 0 || x >= des_x)
		return false;
	else
		return true;
}

void find_way(int des_y, int des_x,int **map) {
	for(int i = 0; i < des_y; i++) {
		for (int j = 0; j < des_x; j++) {
			bool Up_check = true, Left_check = true;

			int ny_1 = i - 1, nx_1 = j;
			int ny_2 = i , nx_2 = j - 1 ;

			if(!Is_Range(nx_1,ny_1,des_x,des_y))
				Up_check = false;

			if (!Is_Range(nx_2, ny_2, des_x, des_y))
				Left_check = false;

			if (Up_check && Left_check)
				map[i][j] = map[ny_1][nx_1] + map[ny_2][nx_2];
			else if (Up_check)
				map[i][j] = map[ny_1][nx_1];
			else if (Left_check)
				map[i][j] = map[ny_2][nx_2];
			
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K;

	long ans;

	int **map = new int*[N];
	for (int i = 0; i < N; i++) {
		map[i] = new int[M];
		fill_n(map[i], M, 0);
	}

	map[0][0] = 1;
	
	find_way(N, M, map);

	ans = map[N - 1][M - 1];

	if (K != 0) {
		int a = K / M, b = K % M - 1;
		if (K % M == 0)
			a = K / M - 1, b = M -1;
	
		ans = map[a][b];
		ans *= map[N - a - 1][M - b - 1];
	}

	cout << ans << '\n';

	for (int i = 0; i < N; i++)
		delete[] map[i];
	
	return 0;
}