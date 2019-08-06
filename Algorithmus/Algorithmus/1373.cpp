#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string input;
	cin >> input;

	deque<int> dq;
	switch (input.size() % 3)
	{
	case 1:
		input = "00" + input;
		break;
	case 2: 
		input = "0" + input;
		break;
	}
	int N = input.size();

	while (N != 0) {
		dq.push_front((input[N-1] - '0') + (input[N - 2] - '0') *2 + (input[N - 3]-'0') * 4);
		N -= 3;
	}
	
	for (auto k : dq)
		cout << k;

	return 0;
}

/*
#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string input;
	cin >> input;

	deque<int> dq;
	int N = input.size()-1;
	while (N >= 3) {
		dq.push_front((input[N] - '0') + (input[N - 1] - '0') *2 + (input[N - 2]-'0') * 4);
		N -= 3;
	}
	if(N == 2)
		dq.push_front((input[N] - '0') + (input[N - 1] - '0') * 2 + (input[N - 2] - '0') * 4);
	else if(N==1)
		dq.push_front((input[N] - '0') + (input[N - 1] - '0') * 2);
	else
		dq.push_front((input[N] - '0'));

	for (auto k : dq)
		cout << k;


	return 0;
}
*/