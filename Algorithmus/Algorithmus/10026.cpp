#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int N,sum=0;
string *input;
bool **visit;

void rgb(int row, int col, char color) {
	if (row < 0 || row >= N || col < 0 || col >= N || color != input[row][col] || visit[row][col] == 1){
		return;
	}

	visit[row][col] = 1;

	rgb(row + 1, col, input[row][col]);
	rgb(row, col + 1, input[row][col]);
	rgb(row, col - 1, input[row][col]);
	rgb(row - 1, col, input[row][col]);
}

int main() {
	cin >> N;
	input = new string[N];
	visit = new bool*[N];

	for (int i = 0; i < N; i++){
		visit[i] = new bool[N];
		fill_n(visit[i], N, false);
	}
	
	getline(cin, input[0]);

	for (int i = 0; i < N; i++) {
		getline(cin, input[i], '\n');
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visit[i][j] == 0) {
				rgb(i, j,input[i][j]);
				sum++;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (input[i][j] == 'G') {
				input[i][j] = 'R';
			}
		}
	}


	cout << sum << ' ';
	
	sum = 0;

	for (int i = 0; i < N; i++) {
		fill_n(visit[i], N, false);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visit[i][j] == 0) {
				rgb(i, j, input[i][j]);
				sum++;
			}
		}
	}

	cout << sum ;
	
	delete[]input;
	for (int i = 0; i < N; i++)
		delete[] visit[i];

	return 0;
}