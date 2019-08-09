#include <iostream>

using namespace std;

long long dp[31][31];

//재귀 함수 이용해서 푸는방법
//long long WH(int W, int H) {
//	if (W == 0)
//		return 1;
//
//	long long temp1 = 0,temp2 = 0;
//
//	//온전히 한 조각 먹었을 떄 ,
//	temp1 = WH(W - 1, H + 1);
//
//	//반 조각 먹었을 떄 
//	if(H != 0)
//		temp2 = WH(W, H - 1);
//
//	return temp1+temp2;
//}

// dp 이용해서 푸는 방법
long long dfs(int W, int H) {
	if (W == 0 && H == 0)
		return 1;
	if (dp[W][H] != 0)
		return dp[W][H];
	if (W != 0)
		dp[W][H] += dfs(W - 1, H + 1);
	if (H != 0)
		dp[W][H] += dfs(W, H - 1);

	return dp[W][H];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;

	while (cin >> N && N != 0) {
		
		cout << dfs(N, 0) << '\n';
	}
	
	return 0;
}