#include <stdio.h>

int dp[5001] = { 0 }, mod = 1000000, len = 0 ;
char a[5000];
int b[5000] = { 0 };

int main() {
	scanf("%s", a);
	for (int i = 0; a[i] != '\0'; i++) {
		b[i + 1] = a[i] - 48;
		len++;
	}
	
	if (b[1] == 0) {
		dp[0] = 0;
		printf("0");
		return 0;
	}
	else {
		dp[0] = 1;
		dp[1] = 1;
	}

	for (int i = 2; i <= len; i++) {
		if (b[i] == 0) {
			int temp = b[i - 1] * 10 + b[i];
			//0�ε� ���ڸ��� 10���� 26 ����
			if (temp >= 10 && temp <= 26) {
				dp[i] = dp[i - 2];
			}
			//0�ε� ���ڸ��� 10���� 26���̰� �ƴ� ���
			else {
				//��ȣ �ؼ� �Ұ���
				printf("0");
				return 0;
			}
		}
		else {
			int temp = b[i - 1] * 10 + b[i];
			int temp2 = b[i - 2] * 10 + b[i - 1];
			
			//���� �ڸ��� ���ڸ��� 10���� 26 ����
			if (temp >= 10 && temp <= 26) {
				//���ڸ��� �վ��ڸ��� 10���� 26����
				if (temp2 >= 10 && temp2 <= 26) {
					dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
				}
				//���ڸ��� �վ��ڸ��� 10���� 26���� �ƴ� ��
				else {
					dp[i] = (dp[i - 1] * 2) % mod;
				}
			}
			//�����ڸ��� ���ڸ��� 10���� 26���̰� �ƴ� ��
			else {
				dp[i] = dp[i - 1] % mod;
			}
		}
	}

	printf("%d", dp[len]);

	return 0;
}

