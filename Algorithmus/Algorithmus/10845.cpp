#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N; 
	string input;
	vector<int> queue;
	cin >> N;

	getline(cin, input);

	for (int i = 0; i < N; i++) {
		getline(cin, input,'\n');
		string command = input.substr(0, input.find(' '));
		if (command == "push") {
			queue.push_back(stoi(input.substr(input.find(' ') + 1, -1)));
		}
		else if (command == "pop") {
			if (queue.empty()){
				cout << -1 << '\n';
			}
			else{
				cout << queue[0] << '\n';
				queue.erase(queue.begin());
			}
		}
		else if (command == "size") {
			cout << queue.size() << '\n';
		}
		else if (command == "empty") {
			if (queue.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (command == "front") {
			if (queue.empty())
				cout << -1 << '\n';
			else
				cout << queue[0] << '\n';
		}
		else if (command == "back") {
			if (queue.empty())
				cout << -1 << '\n';
			else
				cout << queue[queue.size()-1] << '\n';
		}
	}

	
	return 0;
}