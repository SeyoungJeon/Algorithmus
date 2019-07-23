//#include <iostream>
//
//using namespace std;
//
//int main() {
//	int month, day, total_day = 0;;
//	cin >> month >> day; 
//	
//	for (int i = 1; i < month; i++) {
//		if (i % 2 == 1) {
//			if (i == 9 || i == 11) {
//				total_day += 30;
//			}
//			else {
//				total_day += 31;
//			}
//		}
//		else {
//			if (i == 2) {
//				total_day += 28;
//			}
//			else if (i == 8 || i == 10 || i == 12) {
//				total_day += 31;
//			}
//			else {
//				total_day += 30;
//			}
//
//		}
//	}
//
//	for (int i = 0; i < day; i++) {
//		total_day += 1;
//	}
//
//	switch (total_day % 7)
//	{
//	case 0:
//		cout << "SUN" << '\n';
//		break;
//	case 1:
//		cout << "MON" << '\n';
//		break;
//	case 2:
//		cout << "TUE" << '\n';
//		break;
//	case 3:
//		cout << "WED" << '\n';
//		break;
//	case 4:
//		cout << "THU" << '\n';
//		break;
//	case 5:
//		cout << "FRI" << '\n';
//		break;
//	case 6:
//		cout << "SAT" << '\n';
//		break;
//	default:
//		break;
//	}
//	
//	return 0;
//}

#include <iostream>
#include <string>

using namespace std;

int main() {
	int day[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	string week[] = { "SUN","MON","TUE","WED","THU","FRI","SAT","SUN" };
	int m, d, total_day = 0;
	cin >> m >> d;
	for (int i = 0; i < m - 1; i++) {
		total_day += day[i];
	}
	for (int i = 0; i < d; i++) {
		total_day += 1;
	}

	cout << week[total_day % 7] << '\n';
	
	return 0;
}