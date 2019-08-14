#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> *graph;
int V, *visit;
int real_cost = 0, root;

void DFS(int cur,int cost) {
	
	visit[cur] = 1;

	if (real_cost < cost) {
		real_cost = cost;
		root = cur;
	}

	for (size_t i = 0; i < graph[cur].size(); i++) {
		int next = graph[cur][i].first;
		if (visit[next] == 0) {
			DFS(next,cost + graph[cur][i].second);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> V;

	graph = new vector<pair<int, int>>[V + 1];
	visit = new int[V + 1];
	fill_n(visit, V + 1, 0);
	
	for (int i = 0; i < V; i++) {
		int input, pos, other, val, j = 0;
		while (cin >> input) {
			if (input == -1)
				break;

			if (j == 0) {
				pos = input;
			}
			else if (j % 2 == 1) {
				other = input;
			}
			else if (j % 2 == 0) {
				val = input;
				graph[pos].push_back({ other,val });
			}
			j++;
		}
	}

	DFS(1,0);
	fill_n(visit, V + 1, 0);
	real_cost = 0;
	DFS(root, 0);

	cout << real_cost << '\n';
	
	return 0;
}