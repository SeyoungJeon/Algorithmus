#include <iostream>

using namespace std;

int N, L, **map,**map2, ans = 0, *visit;

void DFS(int pos , int cur,int **temp_map) {
	if (cur == N - 1){
		ans++;
		return;
	}

	if (temp_map[pos][cur + 1] == temp_map[pos][cur]) {
		DFS(pos, cur + 1,temp_map);
	}
	//��簡 �������°�
	else if (temp_map[pos][cur] - temp_map[pos][cur + 1] == 1) {
		bool check = true;

		//���θ� ������ �� �迭 ���� ����ٸ�
		if (cur + L >= N){
			return;
		}
	
		//���θ� ������ �� �� ���̰� ���� ���� ���
		for (int i = 1; i <= L; i++) {
			//�ش� ���� ���ΰ� ����
			visit[cur + i] = 1; 
			if (temp_map[pos][cur] - 1 != temp_map[pos][cur + i]){
				check = false;
			}
		}

		if (check) {
			DFS(pos, cur + L, temp_map);
		}
	}
	//��簡 �ö󰡴� ��
	else if (temp_map[pos][cur] - temp_map[pos][cur + 1] == -1) {
		bool check = true;

		//���θ� ������ �� �迭 ������ ����ٸ�
		if (cur - L + 1 < 0)
			return;

		for (int i = 0; i < L; i++) {
			//������ ���̰� ���� �ʰų� �̹� ������ ���ΰ� �������ִٸ�
			if (temp_map[pos][cur] != temp_map[pos][cur - i] || visit[cur-i] == 1) {
				check = false;
			}
		}

		if(check)
			DFS(pos, cur + 1, temp_map);		
	}
}

void solve() {
	for (int i = 0; i < N; i++) {
		fill_n(visit, N, 0);
		DFS(i, 0, map);
		fill_n(visit, N, 0);
		DFS(i, 0, map2);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> L;

	map = new int*[N];
	map2 = new int*[N];
	visit = new int[N];

	for (int i = 0; i < N; i++){
		map[i] = new int[N];
		map2[i] = new int[N];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			map2[j][i] = map[i][j];
		}
	}
	
	solve();

	cout << ans << '\n';
	
	return 0;
}