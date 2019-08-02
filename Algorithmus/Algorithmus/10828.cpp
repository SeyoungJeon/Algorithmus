#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> v;

	int N;
	cin >> N;
	string input;

	//getchar()�� ����ߴµ� sync_with_stdio(false)�� ����߱� ������ �ٸ� �ɷ� �ٲ������ 
	getline(cin, input);
	for (int i = 0; i < N; i++) {
		getline(cin, input);
		string command = input.substr(0, input.find(' '));

		if (command == "push") {
			v.push_back(stoi((input.substr(input.find(' ') + 1, -1))));
		}
		else if (command == "pop") {
			if (v.size() == 0) {
				cout << "-1" << '\n';
			}
			else {
				cout << v[v.size()-1] << '\n';
				v.pop_back();
			}
		}
		else if (command == "size") {
			cout << v.size() << '\n';
		}
		else if (command == "empty") {
			if (v.size() == 0)
				cout << "1" << '\n';
			else
				cout << "0" << '\n';
		}
		else {
			if (v.size() == 0)
				cout << "-1" << '\n';
			else
				cout << v[v.size()-1] << '\n';
		}
	}
	
	return 0;
}

