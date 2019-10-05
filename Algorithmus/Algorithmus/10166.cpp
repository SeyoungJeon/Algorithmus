#include <iostream>
#include <deque>

using namespace std;

int D1, D2, cnt = 0;

//분자 분모를 2차원 배열로 저장하기
bool **check;

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	else{
		return gcd(b, a%b);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> D1 >> D2;

	check = new bool*[D2 + 1];
	
	for (int i = 0; i <= D2; i++){
		check[i] = new bool[D2 + 1];
		fill_n(check[i], D2 + 1, false);
	}

	for (int i = D1; i <= D2; i++) {
		for (int j = 1; j <= i ; j++) {
			int a = i, b = j, gcd_val = gcd(i, j);
			a /= gcd_val;
			b /= gcd_val;

			if (check[a][b])
				continue;

			cnt++;
			check[a][b] = true;

		}

	}

	for (int i = 0; i <= D2; i++)
		delete[] check[i];

	cout << cnt << '\n';

	return 0;
}

// 이상적인 코드
// baekjoon 10166 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

bool visited[2002];

int gcd(int a, int b) {
	if (a % b == 0) return b;
	return gcd(b, a%b);
}

int main()
{
	int D1, D2;
	scanf("%d%d", &D1, &D2);
	int ret = 0;
	for (int i = D1; i <= D2; i++) {
		memset(visited, 0, sizeof(visited));
		ret += i;
		for (int j = D1; j < i; j++) {
			int g = gcd(i, j);
			for (int k = 0; k < i; k += i / g)
				if (!visited[k])
					visited[k] = true, ret--;
		}
	}
	printf("%d\n", ret);
	return 0;
}