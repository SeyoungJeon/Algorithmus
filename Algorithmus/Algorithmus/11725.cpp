#include <iostream>
#include <vector>

using namespace std;

vector<int> *graph;
int N, *parent, *visit;

void DFS(int cur) {
	for (unsigned int i = 0; i < graph[cur].size(); i++) {
		int next = graph[cur][i];
		if(visit[next] == 0){
			visit[cur] = 1;
			parent[next] = cur;
			DFS(next);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	graph = new vector<int>[N + 1];
	parent = new int[N + 1];
	visit = new int[N + 1];
	fill_n(parent, N + 1, 0);
	fill_n(visit, N + 1, 0);
	

	for (int i = 0; i < N-1; i++) {
		int pos, val;
		cin >> pos >> val;
		graph[pos].push_back(val);
		graph[val].push_back(pos);
	}

	DFS(1);

	for (int i = 2; i <= N; i++) {
		cout << parent[i] << '\n';
	}

	return 0;
}