#include <iostream>
#include <vector>

using namespace std;

int T, N, *visit, *graph, *check, result;

void DFS(int s) {
	visit[s] = 1;
	
	int next = graph[s];
	if (visit[next] == 0) {
		DFS(next);
	}
	else if (check[next] == 0) {
		for (int i = next; i != s; i = graph[i]) {
			result++;
		}
		result++;
	}

	check[s] = 1;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	cin >> T;
	while (T-- > 0) {
		cin >> N;
		result = 0;

		graph = new int[N + 1];
		visit = new int[N + 1];
		check = new int[N + 1];
		fill_n(visit, N + 1, 0);
		fill_n(graph, N + 1, 0);
		fill_n(check, N + 1, 0);

		for (int i = 1; i <= N; i++) {
			int input;
			cin >> input;
			graph[i] = input;
		}

		for (int i = 1; i <= N; i++) {
			if (visit[i] == 0) {
				DFS(i);
			}
		}

		cout << N - result << '\n';
	}

	return 0;
}