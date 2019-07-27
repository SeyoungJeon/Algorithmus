#include <iostream>
#include <algorithm>

using namespace std;

int n, total, dp[100001] = { 0 };

int main() {
	cin >> n;

	// �� ���� 1�� �������� ��Ÿ�� �� ���� �ʱ�ȭ 
	for (int i = 0; i <= n; i++) {
		dp[i] = i;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j*j <= i; j++) {
			//�ʱⰪ�� �������� �A�ſ� ���� �ϳ� �� �߰�
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}

	cout << dp[n] << '\n';

	return 0;
}