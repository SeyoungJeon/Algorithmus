#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> v;
int N, **arr, **visited,cnt;
string *input;

void dfs(int row, int col) {
	if (row < 0 || row >= N || col < 0 || col >= N || arr[row][col] == 0 || visited[row][col] == 1)
		return;

	cnt++;

	visited[row][col] = 1;

	//오른쪽
	dfs(row, col+1);
	//왼쪽
	dfs(row, col-1);
	//위쪽
	dfs(row+1, col);
	//아래쪽
	dfs(row - 1, col);

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	
	cin >> N;

	arr = new int*[N];
	input = new string[N];
	visited = new int*[N];
	for (int i = 0; i < N; i++){
		arr[i] = new int[N];
		visited[i] = new int[N];
		fill_n(visited[i], N, 0);
	}

	getline(cin, input[0], '\n');

	for (int i = 0; i < N; i++) {
		getline(cin, input[i], '\n');
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			arr[i][j] = input[i][j]-'0';
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cnt = 0;
			if (arr[i][j] == 1 && visited[i][j] == 0){
				dfs(i, j);
				v.push_back(cnt);
			}
		}
	}

	sort(v.begin(), v.end());

	cout << v.size() << '\n';
	for (auto k : v)
		cout << k << '\n';

	return 0;
}