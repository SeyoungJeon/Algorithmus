#include <iostream>
#include <vector>
#include <string>
#include <limits.h>

using namespace std;

vector<char> v;
int k;
bool visit[10];
string temp, a , ans_min, ans_max;
bool check = false;

void DFS(int depth,int cur, string result) {
	if (depth == k) {
		if (!check) {
			ans_min = result;
			ans_max = result;
			check = true;
		}
		else {
			if (ans_max < result)
				ans_max = result;
		}
		return;
	}

	for (int i = 0; i < 10; i++) {
		if (visit[i])
			continue;

		if (v[depth] == '<') {
			if (cur > i)
				continue;
		}
		else {
			if (cur < i)
				continue;
		}

		temp = to_string(i);
		visit[i] = true;
		DFS(depth + 1, i, result+temp);
		visit[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> k;
	for (int i = 0; i < k; i++) {
		char input;
		cin >> input;
		if (input == '<') {
			v.push_back('<');
		}
		else {
			v.push_back('>');
		}
	}

	for (int i = 0; i < 10; i++) {
		fill_n(visit, 10, false);

		a = to_string(i);
		visit[i] = true;
		DFS(0, i, a);
		visit[i] = false;
	}

	cout << ans_max << '\n';
	cout << ans_min << '\n';
	return 0;
}