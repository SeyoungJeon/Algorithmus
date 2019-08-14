#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> *graph;
int N, *visit, findNode = 0 , real_cost = 0;

void DFS(int cur,int cost) {
	visit[cur] = 1;

	if (real_cost < cost) {
		real_cost = cost;
		findNode = cur;
	}

	for (size_t i = 0; i < graph[cur].size(); i++) {
		int next = graph[cur][i].first;
		if (visit[next] == 0) {
			DFS(next, cost + graph[cur][i].second);
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	
	visit = new int[N + 1];
	graph = new vector<pair<int, int>>[N + 1];
	fill_n(visit, N + 1, 0);

	for (int i = 0; i < N-1; i++) {
		int pos, target, value;
		cin >> pos >> target >> value;
		graph[pos].push_back({ target,value });
		graph[target].push_back({ pos,value });
	}

	DFS(1, 0);
	fill_n(visit, N + 1, 0);
	real_cost = 0;
	DFS(findNode, 0);

	cout << real_cost << '\n';

	return 0;
}