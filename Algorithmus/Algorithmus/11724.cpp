#include <iostream>

using namespace std;

void dfs(int **arr, int *visit, int s, int N) {
	if (visit[s] != 0)
		return;

	visit[s] = 1;

	for (int i = 1; i <= N; i++) {
		if (arr[s][i] != 0 && visit[i] == 0){
			dfs(arr, visit, i, N);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, **arr, *visit,connect = 0;
	cin >> N >> M;

	arr = new int*[N + 1];
	visit = new int[N + 1];
	fill_n(visit, N + 1, 0);
	for (int i = 0; i <= N; i++) {
		arr[i] = new int[N + 1];
		fill_n(arr[i], N + 1, 0);
	}

	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;

		arr[from][to] = 1;
		arr[to][from] = 1;
	}

	for (int i = 1; i <= N; i++) {
		if (visit[i] == 0) {
			dfs(arr, visit, i, N);
			connect++;
		}
	}
	
	cout << connect << '\n';

	for (int i = 0; i <= N; i++)
		delete[] arr[i];

	delete[] visit;

	

	return 0;
}