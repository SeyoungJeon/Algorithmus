#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 1000000000

using namespace std;

vector<int> locate_x;
int N, C, input;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> C;

	for (int i = 0; i < N; i++) {
		cin >> input;
		locate_x.push_back(input);
	}

	int left = 1;
	int right = locate_x[N-1];
	int max_val;

	sort(locate_x.begin(), locate_x.end());

	while (left <= right) {
		// АЃАн
		int space = (left + right) / 2;
		int count = 1;
		int start = locate_x[0];

		for (size_t i = 1; i < locate_x.size(); i++) {
			if (locate_x[i] - start >= space) {
				start = locate_x[i];
				count++;
			}
		}

		if (count >= C)
		{
			max_val = space;
			left = space + 1;
		}
		else
		{
			right = space - 1;
		}

	}

	cout << max_val << '\n';

	return 0;
}