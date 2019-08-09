#include <iostream>

using namespace std;

long long dp[31][31];

//��� �Լ� �̿��ؼ� Ǫ�¹��
//long long WH(int W, int H) {
//	if (W == 0)
//		return 1;
//
//	long long temp1 = 0,temp2 = 0;
//
//	//������ �� ���� �Ծ��� �� ,
//	temp1 = WH(W - 1, H + 1);
//
//	//�� ���� �Ծ��� �� 
//	if(H != 0)
//		temp2 = WH(W, H - 1);
//
//	return temp1+temp2;
//}

// dp �̿��ؼ� Ǫ�� ���
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