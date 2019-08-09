#include <iostream>
#include <vector>

using namespace std;

void dfs(int **arr, int *visit,int n,int N) {
	if (visit[n] != 0)
		return;

	visit[n] = 1;
	cout << n << ' ';

	for (int i = 1; i <= N; i++)
	{
		if (arr[n][i] != 0 && n != i) {
			dfs(arr, visit, i, N);
		}
	}

}

void bfs(int **arr, int *visit, int n, int N) {
	vector<int> v;
	v.push_back(n);
	visit[v[0]] = 1;

	while (v.size() != 0) {
		cout << v[0] << ' ';

		for (int i = 1; i <= N; i++) {
			if (arr[v[0]][i] != 0 && visit[i] == 0 && v[0] != i) {
				visit[i] = 1;
				v.push_back(i);
			}
		}
		v.erase(v.begin());
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M , first;
	int **arr,*visit;

	cin >> N >> M >> first;

	arr = new int*[N+1];
	visit = new int[N+1];
	fill_n(visit, N + 1, 0);

	for (int i = 0; i <= N; i++) {
		arr[i] = new int[N + 1];
		fill_n(arr[i], N + 1, 0);
	}

	for (int i = 0; i < M; i++)
	{
		int start, end;
		cin >> start >> end;
		arr[start][end] = 1;
		arr[end][start] = 1;
	}

	dfs(arr, visit, first, N);
	fill_n(visit, N + 1, 0);
	cout << '\n';
	bfs(arr, visit, first, N);

	for (int i = 0; i <= N; i++) {
		delete[] arr[i];
	}

	delete[] visit;
		
	return 0;
}