#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string input;
	vector<pair<char,int>> v;
	int total = 0;

	cin >> input;
	
	for (int i = 0; i < input.size() ; i++) {
		// 문자가 ( 일 때, 길이 1로 설정하면서 vector에 넣음 
		if (input[i] == '(') {
			v.push_back(make_pair('(',1));
		}
		else {
			// 문자가 ) 면서 그 전의 문자가 ( 일 때 , 즉, 레이저 일때
			if (input[i - 1] == '(') {
				// 전전 문자까지의 조각을 1씩 더해줌 
				for (int j = 0; j < v.size() - 1; j++) {
					v[j].second += 1;
				}
			}
			// 문자가 ) 면서 그 전의 문자가 ) 일 떄, 즉 레이저가 아닐 때
			else {
				//마지막 문자의 조각 길이를 총합에 더해주면서 stack에서 제거함
				total += v.back().second;
			}
			v.pop_back();
		}
	}

	cout << total << '\n';
	return 0;
}