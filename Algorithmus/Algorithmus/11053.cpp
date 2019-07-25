#include <iostream>
#include <algorithm>

using namespace std;

int N, max_arr[1001],arr[1001],t;

int main() {

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= N; i++) {
		max_arr[i] = 1;
		for (int j = 1; j < i; j++) {
			if (arr[i] > arr[j]){
				max_arr[i] = max(max_arr[j]+1, max_arr[i]);
			}
		}
		t = max(max_arr[i], t);
	}
	cout << t << '\n';
	
	return 0;
}