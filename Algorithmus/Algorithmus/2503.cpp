#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Answer {
	string a;
	int s, b;
};

vector<Answer> v;
int N,ans=0;

int Return_Strike(string a, string b) {
	int cnt = 0;
	if (a[0] == b[0])
		cnt++;
	if (a[1] == b[1])
		cnt++;
	if (a[2] == b[2])
		cnt++;

	return cnt;
}

int Return_Ball(string a, string b) {
	int cnt = 0;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i != j && a[i] == b[j]) {
				cnt++;
			}
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		string q;
		int s, b;
		cin >> q >> s >> b;
		Answer m;
		m.a = q;
		m.s = s;
		m.b = b;
		v.push_back(m);
	}

	for (int i = 123; i <= 987; i++) {
		string temp = to_string(i);
		if (temp[0] == temp[1] || temp[1] == temp[2] || temp[2] == temp[0] ||
			temp[0] == '0' || temp[1] == '0' || temp[2] == '0') {
			continue;
		}
		bool check = true;
		for (auto k : v) {
			if (Return_Strike(k.a, temp) != k.s || Return_Ball(k.a, temp) != k.b) {
				check = false;
			}
		}
		if (check)
			ans++;
	}

	cout << ans << '\n';


	return 0;
}