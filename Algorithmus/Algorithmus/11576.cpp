#include <iostream>
#include <vector>
#include <math.h>
#include <string>

using namespace std;

long long ConvertAto10(vector<long long> v,int A) {
	long long sum = 0;
	for (unsigned int i = 0; i < v.size(); i++) {
		sum += v[i] * pow(A, v.size() - 1 - i);
	}

	return sum;
}

void Convert10toB(long long Num_10,int B) {
	string result = "";
	while (Num_10 != 0) {
		result = " " + to_string(Num_10%B) + result;
		Num_10 /= B;
	}
	cout << result.substr(1,-1) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int A, B, M ;
	long long Num_10;
	vector<long long>v;
	cin >> A >> B;
	cin >> M;
	for (int i = 0; i < M; i++) {
		long long temp;
		cin >> temp;
		v.push_back(temp);
	}

	// A진법 10진수로 변환
	Num_10 = ConvertAto10(v, A);

	// 10진수 B진법으로 변환
	Convert10toB(Num_10, B);

	return 0;
}