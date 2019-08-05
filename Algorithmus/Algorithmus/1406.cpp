#include <iostream>
#include <string>
#include <list>
#include <string.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	string input,command, real_command;;
	list<char> list;

	getline(cin, input, '\n');

	for (unsigned int i = 0; i < input.size(); i++) {
		list.push_back(input.at(i));
	}

	auto cur_pos = list.end();

	cin >> N;
	getline(cin, command, '\n');

	for (int i = 0; i < N; i++) {
		getline(cin, command, '\n');
		
		real_command = command.substr(0, command.find(' '));
		if (real_command == "P") {
			char temp[10];
			strcpy(temp,command.substr(command.find(' ') + 1, -1).c_str());
			list.insert(cur_pos, temp[0]);
		}
		else if (real_command == "L") {
			if (cur_pos != list.begin())
				cur_pos--;
		}
		else if (real_command == "D") {
			if (cur_pos != list.end())
				cur_pos++;
		}
		else if (real_command == "B") {
			if (cur_pos != list.begin()) {
				cur_pos = list.erase(--cur_pos);
			}
		}
	}

	for (auto iter = list.begin(); iter != list.end(); iter++)
		cout << *iter;
	
	cout << '\n';
	return 0;
}