#include <iostream>

using namespace std;

int w, h, **arr, **visit,cnt;

//int dx[8] = { 1, 1, 1, 0, -1, -1, -1, 0 };
//int dy[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };

void DFS(int row, int col) {
	if (row < 0 || row >= h || col < 0 || col >= w || visit[row][col] == 1 || arr[row][col] == 0)
		return;

	visit[row][col] = 1;

	//오른쪽
	DFS(row+1, col);
	//오른쪽 아래
	DFS(row+1, col+1);
	//오른쪽 위
	DFS(row+1, col-1);
	//위
	DFS(row, col+1);
	DFS(row, col-1);
	DFS(row-1, col);
	DFS(row-1, col+1);
	DFS(row-1, col-1);
}

int main() {
	
	while (cin >> w >> h) {
		if (w == 0 && h == 0)
			break;

		cnt = 0;
		arr = new int*[h];
		visit = new int*[h];
		for (int i = 0; i < h; i++) {
			arr[i] = new int[w];
			visit[i] = new int[w];
			fill_n(visit[i], w, 0);
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> arr[i][j];
			}
		}

		

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (arr[i][j] == 1 && visit[i][j] == 0){
					DFS(i, j);
					cnt++;
				}
			}
		}

		cout << cnt << '\n';
	}
}