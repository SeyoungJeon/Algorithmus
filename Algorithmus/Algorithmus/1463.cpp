#include <iostream>
#include <limits.h>
#include <algorithm>

using namespace std;

/* 재귀로 DFS 구현해서 품
int recursive(int X,int total) {
	int temp_total;
	int temp1=INT_MAX, temp2= INT_MAX, temp3= INT_MAX;
	
	if (X == 1)
	{
		return total;
	}

	if (X % 2 == 0) {
		temp1 = recursive(X/2, total + 1);
	}
	if (X % 3 == 0) {
		temp2 = recursive(X / 3, total + 1);
	}

	temp3 = recursive(X - 1, total + 1);
	
	temp_total = temp1;
	if (temp_total > temp2)
		temp_total = temp2;
	if (temp_total > temp3)
		temp_total = temp3;

	return temp_total;
}

int main() {
	int X;
	int total;
	cin >> X;

	total = recursive(X, 0);
	
	cout << total << '\n';

	return 0;
}
*/

// 정답 bottom-up 방식으로 풀어야함 (반복문)
int main() {
	int X;
	cin >> X;
	int* arr = new int[X + 1]();
	
	arr[1] = 0;

	for (int i = 2 ; i <= X; i++) {
		arr[i] = arr[i - 1] + 1;
		if (i % 2 == 0) {
			arr[i] = min(arr[i], arr[i / 2] + 1);
		}
		if (i % 3 == 0) {
			arr[i] = min(arr[i],arr[i / 3] + 1);
		}
	}

	cout << arr[X] << '\n';

	delete[] arr;

	return 0;
}