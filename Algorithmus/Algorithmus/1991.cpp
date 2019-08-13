#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N;
vector<int> *graph;

void DFS_1(int cur) {

	if (graph[cur].empty())
		return;

	cout << char(cur + 'A');

	int left = graph[cur][0];
	int right = graph[cur][1];

	if (left != -19)
		DFS_1(left);
	if (right != -19)
		DFS_1(right);

}

void DFS_2(int cur) {

	if (graph[cur].empty())
		return;

	int left = graph[cur][0];
	int right = graph[cur][1];

	if (left != -19)
		DFS_2(left);
	if (right != -19)
		DFS_2(right);

	cout << char(cur + 'A');
}

void DFS_3(int cur) {

	if (graph[cur].empty())
		return;

	int left = graph[cur][0];
	int right = graph[cur][1];


	if (left != -19){
		DFS_3(left);
	}
	cout << char(cur + 'A');
	if (right != -19){
		DFS_3(right);
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	graph = new vector<int>[N];

	for (int i = 0; i < N; i++) {
		int pos = 0;

		for (int j = 0; j < 3; j++) {
			char input;
			cin >> input;
			if (j == 0) {
				pos = input - 'A';
			}
			else {
				graph[pos].push_back(int(input - 'A'));
			}
		}
	}

	//전위 순회
	DFS_1(0);
	cout << '\n';
	//중위 순회
	DFS_3(0);
	cout << '\n';
	//후위 순회
	DFS_2(0);
	cout << '\n';

	return 0;
}