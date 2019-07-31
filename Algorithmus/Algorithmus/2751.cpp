#include <stdio.h>
#include <stdlib.h>

int N, *a, *b;

void Merge(int left, int mid, int right) {
	int i = left, j = mid + 1, k = left;

	// ���� ����Ʈ ������ ����Ʈ ���ϸ鼭 ���ο� �迭�� ������������ �ֱ�
	while (i <= mid && j <= right) {
		a[i] <= a[j] ? b[k++] = a[i++] : b[k++] = a[j++];
	}

	// ���� ����Ʈ �Ǵ� ������ ����Ʈ�� ���� ���ҵ� ���ο� �迭�� �߰������� �ֱ�
	if (i > mid) {
		for (int l = j; l <= right; l++) {
			b[k++] = a[l];
		}
	}
	else {
		for (int l = i; l <= mid; l++) {
			b[k++] = a[l];
		}
	}

	// ���ĵ� ���ο� �迭�� ������ �迭�� �����ϱ�
	for (int l = left; l <= right; l++) {
		a[l] = b[l];
	}
}

void MergeSort(int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;		// ������ ����
		MergeSort(left, mid);				// ���� �� ����
		MergeSort(mid + 1, right);		// ������ �� ����
		Merge(left, mid, right);		// ����
	}

}

int main() {
	scanf("%d", &N);
	a = (int*)malloc(sizeof(int)*(N + 1));
	b = (int*)malloc(sizeof(int)*(N + 1));
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &a[i]);
	}

	MergeSort(1, N);

	for (int i = 1; i <= N; i++) {
		printf("%d\n", a[i]);
	}
	
	free(a);
	free(b);

	return 0;
}