#include <iostream>
#include <vector>
using namespace std;

int arr[1000001] = { 0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int input;

	for (int i = 2; i <= 1000000; i++) {
		for (int j = 2; j*i <= 1000000; j++)
			arr[i*j] = 1;
	}

	while (cin >> input) {
		if (input == 0)
			break;

		bool check = false;
		vector<int> v;

		

		for (int i = 2; i <= input; i++) {
			if (arr[i] == 0)
				v.push_back(i);
		}

		/*for (unsigned int i = 1; i < v.size(); i++) {
			for(int j= v.size()-1; j>=1 ; j--)
				if (v[i] + v[j] == input) {
					cout << input << " = " << v[i] << " + " << v[j] << '\n';
					check = true;
					break;
				}
			if (check)
				break;
		}*/
		for (int i = 1; i < v.size(); i++) {
			if (input - 1 == v[v.size() - 1]) {
				if(v[i] + v[v.size()-2] == input){
					cout << input << " = " << v[i] << " + " << v[v.size()-2] << '\n';
					check = true;
					break;
				}
			}
			else {
				if (v[i] + v[v.size() - 1] == input) {
					cout << input << " = " << v[i] << " + " << v[v.size() - 1] << '\n';
					check = true;
					break;
				}
			}
		}

		

		if (!check)
			cout << "Goldbach's conjecture is wrong." << '\n';
	}

	return 0;
}