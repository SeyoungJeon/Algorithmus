#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<long long, int>> v;
long long temp1,temp2, input;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> input;
		auto iter = v.begin();
		bool check = false;
		while (iter != v.end()) {
			if (iter->first == input) {
				temp1 = iter->first;
				temp2 = iter->second;
				iter = v.erase(iter);
				check = true;
				break;
			}
			else {
				++iter;
			}
		}
		if (check) {
			v.push_back(make_pair(temp1, temp2 + 1));
		}
		else {
			v.push_back(make_pair(input, 1));
		}
	}

	auto iter = v.begin();
	long long max_val = 0;
	long long output;
	while (iter != v.end()) {
		if (iter->second > max_val) {
			max_val = iter->second;
			output = iter->first;
		}
		else if(iter->second == max_val){
			if (output > iter->first) {
				output = iter->first;
			}
		}
		++iter;
	}

	cout << output << '\n';

	return 0;
}