#include <iostream>
#include <deque>
#include <algorithm>
#include <limits.h>

using namespace std;

deque<pair<int, int>> house,chicken,temp;
int N, M, ans = INT_MAX;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

//��� ġŲ �Ÿ� ���ϱ�
int Min_Chicken_Road(deque<pair<int,int>> chicken) {
	int total = 0;

	//�� ���� ���õ� ġŲ �� �ּ� �Ÿ� ���ϱ�
	for (auto h : house) {
		int min_val = INT_MAX;
		for (auto c : chicken) {
			int y_val = h.first > c.first ? h.first - c.first : c.first - h.first;
			int x_val = h.second > c.second ? h.second - c.second : c.second - h.second;
			min_val = min(min_val, x_val + y_val);
		}
		// �� �������� ġŲ �ּ� �Ÿ� ���ϱ�
		total += min_val;
	}
	return total;
}

void DFS(int depth,int k) {
	//���õ� ġŲ M���� �� ��� ġŲ �Ÿ� ���ϱ�
	if (depth == M){
		ans = min(ans, Min_Chicken_Road(temp));
		return;
	}

	for (size_t i = k; i < chicken.size(); i++) {
		//������ ġŲ �� �ֱ�
		temp.push_back({ chicken[i].first,chicken[i].second });
		DFS(depth + 1, i+1);
		temp.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int input;
			cin >> input;
			if (input == 1) {
				house.push_back({i, j});
			}
			else if (input == 2) {
				chicken.push_back({ i,j });
			}
		}
	}

	DFS(0, 0);

	cout << ans << '\n';

	return 0;
}