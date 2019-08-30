#include <iostream>
#include <queue>
#include <string>

// 극
#define N 0 
#define S 1

// 방향
#define DIR_TIME 1
#define DIR_OTHER_TIME -1

using namespace std;

queue<pair<int, int>> input;
int **map,K,*visit,ans = 0;
bool check[3];

//시계 방향 회전
int* Change_TIME_DIR(int *temp_map) {
	int *result_map;
	result_map = new int[8];

	for (int i = 1; i < 8; i++) {
		result_map[i] = temp_map[i-1];
	}
	result_map[0] = temp_map[7];

	return result_map;
}

//반시계 방향 회전
int* Change_OTHER_TIME_DIR(int *temp_map) {
	int *result_map;
	result_map = new int[8];

	for (int i = 0; i < 7; i++) {
		result_map[i] = temp_map[i + 1];
	}
	result_map[7] = temp_map[0];

	return result_map;
}

void DFS(int num,int dir) {
	int *result = NULL;
	visit[num] = 1;

	switch (dir) {
	case DIR_TIME:
		result = Change_TIME_DIR(map[num]);
		break;
	case DIR_OTHER_TIME:
		result = Change_OTHER_TIME_DIR(map[num]);
		break;
	}
	
	for (int i = 0; i < 8; i++) {
		map[num][i] = result[i];
	}

	if (num == 0) {
		if (check[0] && !visit[num + 1]) {
			switch (dir) {
			case DIR_TIME:
				DFS(num + 1, DIR_OTHER_TIME);
				break;
			case DIR_OTHER_TIME:
				DFS(num + 1, DIR_TIME);
				break;
			}
		}
	}
	else if (num == 3) {
		if (check[2] && !visit[num - 1]) {
			switch (dir) {
			case DIR_TIME:
				DFS(num - 1, DIR_OTHER_TIME);
				break;
			case DIR_OTHER_TIME:
				DFS(num - 1, DIR_TIME);
				break;
			}
		}
	}
	else if (num == 2){
		if (check[2] && !visit[num + 1]) {
			switch (dir) {
			case DIR_TIME:
				DFS(num + 1, DIR_OTHER_TIME);
				break;
			case DIR_OTHER_TIME:
				DFS(num + 1, DIR_TIME);
				break;
			}
		}
		if (check[1] && !visit[num - 1]) {
			switch (dir) {
			case DIR_TIME:
				DFS(num - 1, DIR_OTHER_TIME);
				break;
			case DIR_OTHER_TIME:
				DFS(num - 1, DIR_TIME);
				break;
			}
		}
	}
	else if (num==1){
		if (check[1] && !visit[num + 1]) {
			switch (dir) {
			case DIR_TIME:
				DFS(num + 1, DIR_OTHER_TIME);
				break;
			case DIR_OTHER_TIME:
				DFS(num + 1, DIR_TIME);
				break;
			}
		}
		if (check[0] && !visit[num - 1]) {
			switch (dir) {
			case DIR_TIME:
				DFS(num - 1, DIR_OTHER_TIME);
				break;
			case DIR_OTHER_TIME:
				DFS(num - 1, DIR_TIME);
				break;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string temp_input;

	map = new int*[4];
	visit = new int[4];

	for (int i = 0; i < 4; i++) {
		map[i] = new int[8];
		getline(cin, temp_input, '\n');
		for (size_t j = 0; j < temp_input.size(); j++) {
			map[i][j] = int(temp_input[j]) - '0';
		}
	}

	cin >> K;
	for (int i = 0; i < K; i++) {
		int num, dir;
		cin >> num >> dir;
		input.push({ num,dir });
	}

	while (!input.empty()) {
		int num = input.front().first - 1;
		int dir = input.front().second;
		input.pop();

		fill_n(check, 3, false);
		fill_n(visit, 4, 0);

		if (map[0][2] != map[1][6])
			check[0] = true;
		if (map[1][2] != map[2][6])
			check[1] = true;
		if (map[2][2] != map[3][6])
			check[2] = true;
		
		DFS(num, dir);
	}

	for (int i = 0; i < 4; i++) {
		if (map[i][0] == N) {
			continue;
		}
		int result = 1;
		for (int j = 0; j < i; j++)
			result *= 2;

		ans += result;
	}

	cout << ans << '\n';

	return 0;
}