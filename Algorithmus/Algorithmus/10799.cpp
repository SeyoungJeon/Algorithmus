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
		// ���ڰ� ( �� ��, ���� 1�� �����ϸ鼭 vector�� ���� 
		if (input[i] == '(') {
			v.push_back(make_pair('(',1));
		}
		else {
			// ���ڰ� ) �鼭 �� ���� ���ڰ� ( �� �� , ��, ������ �϶�
			if (input[i - 1] == '(') {
				// ���� ���ڱ����� ������ 1�� ������ 
				for (int j = 0; j < v.size() - 1; j++) {
					v[j].second += 1;
				}
			}
			// ���ڰ� ) �鼭 �� ���� ���ڰ� ) �� ��, �� �������� �ƴ� ��
			else {
				//������ ������ ���� ���̸� ���տ� �����ָ鼭 stack���� ������
				total += v.back().second;
			}
			v.pop_back();
		}
	}

	cout << total << '\n';
	return 0;
}