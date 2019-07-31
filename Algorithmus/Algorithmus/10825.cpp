#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

struct Point {
	char name[20];
	int kor;
	int eng;
	int math;
};

bool compare(Point &a, Point &b) {
	if (a.kor > b.kor) {
		return true;
	}
	else if (a.kor == b.kor) {
		if (b.eng > a.eng) {
			return true;
		}
		else if (a.eng == b.eng) {
			if (a.math > b.math) {
				return true;
			}
			else if (a.math == b.math) {
				if (strcmp(a.name,b.name) < 0 ) {
					return true;
				}
				else {
					return false;
				}
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

int main() {
	int N;
	scanf("%d", &N);

	Point *point = new Point[N];

	for (int i = 0; i < N; i++) {
		scanf("%s %d %d %d", point[i].name, &point[i].kor, &point[i].eng, &point[i].math);
	}

	sort(point,point + N, compare);

	for (int i = 0; i < N; i++) {
		printf("%s\n", point[i].name);
	}
	return 0;
}