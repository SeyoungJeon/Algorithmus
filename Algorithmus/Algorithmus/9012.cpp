#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	string input;

	for (int i = 0; i < T; i++) {
		vector<char> v;
		bool check = true;
		cin >> input;
		
		for (int j = 0; j < input.size(); j++) {
			if (input.at(j) == '(') {
				v.push_back('(');
			}
			else {
				if (v.size() != 0)
					v.pop_back();
				else
					check = false;
			}
		}
		if (v.size() == 0 && check)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}