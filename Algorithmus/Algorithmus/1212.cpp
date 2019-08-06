#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string input,result ="";
	cin >> input;

	for (unsigned int i = 0; i < input.size(); i++) {
		int temp = (int)input[i] - '0';
		string B="";
		while (temp != 0)
		{
			B = to_string(temp % 2) + B;
			temp /= 2;
		}
		if (i != 0) {
			switch (B.size())
			{
			case 0:
				B = "000";
				break;
			case 1:
				B = "00" + B;
				break;
			case 2:
				B = "0" + B;
				break;
			}
		}
		else if(B == ""){
			B = "0";
		}
		result += B;
	}

	cout << result << '\n';
	return 0;
}