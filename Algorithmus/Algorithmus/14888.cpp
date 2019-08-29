#include <iostream>
#include <deque>
#include <limits.h>

using namespace std;

deque<int> q;
int N, arr[4];
long long min_val = LLONG_MAX, max_val = LLONG_MIN;


void DFS(int plus,int minus, int multi, int divide,long long cur_val) {
	if (plus == 0 && minus == 0 && multi == 0 && divide == 0){
		if (min_val > cur_val) {
			min_val = cur_val;
		}
		if (max_val < cur_val) {
			max_val = cur_val;
		}
		return;
	}

	int q_val = q.front();
	
	if (plus > 0) {
		q.pop_front();
		DFS(plus-1,minus,multi,divide,cur_val + q_val);
		q.push_front(q_val);
	}
	if (minus > 0) {
		q.pop_front();
		DFS(plus, minus-1, multi, divide, cur_val - q_val);
		q.push_front(q_val);
	}
	if (multi > 0){
		q.pop_front();
		DFS(plus, minus, multi-1, divide, cur_val * q_val);
		q.push_front(q_val);
	}
	if (divide > 0) {
		q.pop_front();
		DFS(plus, minus, multi, divide-1, cur_val / q_val);
		q.push_front(q_val);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		q.push_back(input);
	}

	for (int i = 0; i < 4; i++) {
		cin >> arr[i];
	}

	int cur_val = q.front();
	q.pop_front();

	DFS(arr[0],arr[1],arr[2],arr[3],cur_val);

	cout << max_val << '\n' << min_val << '\n';

	return 0;
}