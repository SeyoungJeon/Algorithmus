#include <iostream>
#include <vector>
#define MAX 1001

using namespace std;

void DFS(vector<int> *graph, int *visit, int s) {
	visit[s] = 1;

	for (int i = 0; i < graph[s].size(); i++) {
		int next = graph[s][i];
		if(visit[next] == 0)
			DFS(graph, visit, graph[s][i]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T, N;
	vector<int> graph[MAX];
	int visit[MAX];

	cin >> T;

	for (int i = 0; i < T; i++) {
		int cycle = 0;
		cin >> N;
		for (int i = 1; i < MAX; i++)
			graph[i].clear();

		fill_n(visit, MAX, 0);

		for (int j = 1; j <= N; j++) {
			int input;
			cin >> input;
			graph[j].push_back(input);
		}

		for (int j = 1; j <= N; j++){
			if (visit[j] == 0) {
				DFS(graph, visit, j);
				cycle++;
			}
		}

		cout << cycle << '\n';
	}

	return 0;
}