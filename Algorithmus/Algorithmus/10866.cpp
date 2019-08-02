#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	string input;
	deque<int> deque;
	cin >> N;

	getline(cin, input);

	for (int i = 0; i < N; i++) {
		getline(cin, input, '\n');
		string command = input.substr(0, input.find(' '));
		if (command == "push_front") {
			deque.push_front(stoi(input.substr(input.find(' ') + 1, -1)));
		}
		else if (command == "push_back") {
			deque.push_back(stoi(input.substr(input.find(' ') + 1, -1)));
		}
		else if (command == "pop_front") {
			if (deque.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << deque.front() << '\n';
				deque.pop_front();
			}
		}
		else if (command == "pop_back") {
			if (deque.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << deque.back() << '\n';
				deque.pop_back();
			}
		}
		else if (command == "size") {
			cout << deque.size() << '\n';
		}
		else if (command == "empty") {
			if (deque.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (command == "front") {
			if (deque.empty())
				cout << -1 << '\n';
			else
				cout << deque.front() << '\n';
		}
		else if (command == "back") {
			if (deque.empty())
				cout << -1 << '\n';
			else
				cout << deque.back() << '\n';
		}
	}


	return 0;
}