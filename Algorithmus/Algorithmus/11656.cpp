#include <iostream> 
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<string> v;
	string input;
	cin >> input;
	
	for (int i = 0; i < input.size(); i++) {
		v.push_back(input.substr(i, input.size()));
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}

	return 0;
}