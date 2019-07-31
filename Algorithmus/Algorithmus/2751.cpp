#include <stdio.h>
#include <stdlib.h>

int N, *a, *b;

void Merge(int left, int mid, int right) {
	int i = left, j = mid + 1, k = left;

	// 왼쪽 리스트 오른쪽 리스트 비교하면서 새로운 배열에 오름차순으로 넣기
	while (i <= mid && j <= right) {
		a[i] <= a[j] ? b[k++] = a[i++] : b[k++] = a[j++];
	}

	// 왼쪽 리스트 또는 오른쪽 리스트에 남은 원소들 새로운 배열에 추가적으로 넣기
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

	// 정렬된 새로운 배열을 기존에 배열에 복사하기
	for (int l = left; l <= right; l++) {
		a[l] = b[l];
	}
}

void MergeSort(int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;		// 반으로 분할
		MergeSort(left, mid);				// 왼쪽 반 정렬
		MergeSort(mid + 1, right);		// 오른쪽 반 정렬
		Merge(left, mid, right);		// 병합
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