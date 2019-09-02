#include <iostream>
#include <deque>
#include <string>

#define U 0
#define D 1
#define F 2
#define B 3
#define L 4
#define R 5

#define TIME '+'
#define OTHER_TIME '-'

using namespace std;

deque<string> dir;
char map[6][3][3], temp_map[6][3][3];
char color[6] = { 'w','y','r','o','g','b' };
int N;

// 한 면 시계 방향으로 회전
void TIME_Rotate(int rotate) {
	char temp_map[3][3];

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			temp_map[i][j] = map[rotate][i][j];
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			map[rotate][i][j] = temp_map[2 - j][i];
		}
	}
}

// 윗면 기준 OK
void Change_U() {
	int temp[3];

	for (int i = 0; i < 3; i++)
		temp[i] = map[F][0][i];
	for (int i = 0; i < 3; i++)
		map[F][0][i] = map[R][0][i];
	for (int i = 0; i < 3; i++)
		map[R][0][i] = map[B][0][i];
	for (int i = 0; i < 3; i++)
		map[B][0][i] = map[L][0][i];
	for (int i = 0; i < 3; i++)
		map[L][0][i] = temp[i];
}

// 아랫면 기준 OK
void Change_D() {
	int temp[3];

	for (int i = 0; i < 3; i++)
		temp[i] = map[F][2][i];
	for (int i = 0; i < 3; i++)
		map[F][2][i] = map[L][2][i];
	for (int i = 0; i < 3; i++)
		map[L][2][i] = map[B][2][i];
	for (int i = 0; i < 3; i++)
		map[B][2][i] = map[R][2][i];
	for (int i = 0; i < 3; i++)
		map[R][2][i] = temp[i];
}

// 왼쪽면 기준 OK
void Change_L() {
	int temp[3];

	for (int i = 0; i < 3; i++)
		temp[i] = map[F][i][0];
	for (int i = 0; i < 3; i++)
		map[F][i][0] = map[U][i][0];
	for (int i = 0; i < 3; i++)
		map[U][i][0] = map[B][2 - i][2];
	for (int i = 0; i < 3; i++)
		map[B][i][2] = map[D][2 - i][0];
	for (int i = 0; i < 3; i++)
		map[D][i][0] = temp[i];
}

// 오른쪽면 기준 OK
void Change_R() {
	int temp[3];

	for (int i = 0; i < 3; i++)
		temp[i] = map[F][i][2];
	for (int i = 0; i < 3; i++)
		map[F][i][2] = map[D][i][2];
	for (int i = 0; i < 3; i++)
		map[D][i][2] = map[B][2 - i][0];
	for (int i = 0; i < 3; i++)
		map[B][i][0] = map[U][2 - i][2];
	for (int i = 0; i < 3; i++)
		map[U][i][2] = temp[i];
}

// 앞면 기준 OK
void Change_F() {
	int temp[3];

	for (int i = 0; i < 3; i++)
		temp[i] = map[U][2][i];
	for (int i = 0; i < 3; i++)
		map[U][2][i] = map[L][2 - i][2];
	for (int i = 0; i < 3; i++)
		map[L][i][2] = map[D][0][i];
	for (int i = 0; i < 3; i++)
		map[D][0][i] = map[R][2 - i][0];
	for (int i = 0; i < 3; i++)
		map[R][i][0] = temp[i];
}

// 뒷면 기준 OK
void Change_B() {
	int temp[3];

	for (int i = 0; i < 3; i++)
		temp[i] = map[U][0][i];
	for (int i = 0; i < 3; i++)
		map[U][0][i] = map[R][i][2];
	for (int i = 0; i < 3; i++)
		map[R][i][2] = map[D][2][2 - i];
	for (int i = 0; i < 3; i++)
		map[D][2][i] = map[L][i][0];
	for (int i = 0; i < 3; i++)
		map[L][i][0] = temp[2 - i];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int k = 0; k < 6; k++) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				map[k][i][j] = color[k];
				temp_map[k][i][j] = color[k];
			}
		}

	}

	for (int i = 0; i < N; i++) {
		int input1;
		cin >> input1;
		for (int j = 0; j < input1; j++) {
			string input;
			cin >> input;
			dir.push_back(input);
		}

		while (!dir.empty()) {
			char temp1 = dir.front()[0];
			char temp2 = dir.front()[1];
			dir.pop_front();

			switch (temp1) {
			case 'U':
				switch (temp2) {
				case TIME:
					Change_U();
					TIME_Rotate(0);
					break;
				case OTHER_TIME:
					// 시계 방향으로 3번 돌리면 반시계 방향과 같음
					for (int i = 0; i < 3; i++) {
						Change_U();
						TIME_Rotate(0);
					}
					break;
				}
				break;
			case 'D':
				switch (temp2) {
				case TIME:
					Change_D();
					TIME_Rotate(1);
					break;
				case OTHER_TIME:
					for (int i = 0; i < 3; i++) {
						Change_D();
						TIME_Rotate(1);
					}
					break;
				}
				break;
			case 'F':
				switch (temp2) {
				case TIME:
					Change_F();
					TIME_Rotate(2);
					break;
				case OTHER_TIME:
					for (int i = 0; i < 3; i++) {
						Change_F();
						TIME_Rotate(2);
					}
					break;
				}
				break;
			case 'B':
				switch (temp2) {
				case TIME:
					Change_B();
					TIME_Rotate(3);
					break;
				case OTHER_TIME:
					for (int i = 0; i < 3; i++) {
						Change_B();
						TIME_Rotate(3);
					}
					break;
				}
				break;
			case 'L':
				switch (temp2) {
				case TIME:
					Change_L();
					TIME_Rotate(4);
					break;
				case OTHER_TIME:
					for (int i = 0; i < 3; i++) {
						Change_L();
						TIME_Rotate(4);
					}
					break;
				}
				break;
			case 'R':
				switch (temp2) {
				case TIME:
					Change_R();
					TIME_Rotate(5);
					break;
				case OTHER_TIME:
					for (int i = 0; i < 3; i++) {
						Change_R();
						TIME_Rotate(5);
					}
					break;
				}
				break;
			}

		}

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << map[0][i][j];
			}
			cout << '\n';
		}

		for (int k = 0; k < 6; k++) {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					map[k][i][j] = temp_map[k][i][j];
				}
			}
		}
	}

	return 0;
}