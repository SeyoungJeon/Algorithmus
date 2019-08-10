#include <iostream>
#include <vector>

#define MAX 20001

using namespace std;

void dfs(vector<int> *graph, int *color, int s, int c) {
	color[s] = c;

	for (int i = 0; i < graph[s].size(); i++) {
		int next = graph[s][i];
		if (!color[next])
			dfs(graph, color, next, 3 - c);
	}
}

bool IsCheck(vector<int> *graph, int *color,int V) {
	for (int i = 1; i <= V; i++) {
		for (int j = 0; j < graph[i].size(); j++) {
			int next = graph[i][j];
			if (color[i] == color[next])
				return false;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int K, color[MAX];
	vector<int> graph[MAX];
	
	cin >> K;

	for (int i = 0; i < K; i++) {
		int V, E;
		cin >> V >> E;

		for (int j = 1; j <= V; j++)
			graph[j].clear();
		fill_n(color, MAX, 0);

		for (int j = 0; j < E; j++) {
			int from, to;
			cin >> from >> to;
			graph[from].push_back(to);
			graph[to].push_back(from);
		}


		for (int j = 1; j <= V; j++) {

			if (color[j] == 0)
				dfs(graph, color, j, 1);
		}
		
		if (IsCheck(graph,color,V))
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';

	}

	return 0;
}
