#include<iostream>

using namespace std;

int A[1000001];
void swap(int *x, int *y);
void qi_sort(int *arr, int p, int n);
int partition(int * arr, int p, int n);
int choosePivot(int l, int h);

int main() {
	int n;

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &A[i]);
	}

	qi_sort(A, 1, n);

	for (int i = 1; i <= n; i++) {
		printf("%d\n", A[i]);
	}
}

void qi_sort(int *arr, int p, int n) {
	if (p < n) {
		int q = partition(arr, p, n);
		qi_sort(arr, p, q - 1);
		qi_sort(arr, q + 1, n);
	}
}

int partition(int *arr, int p, int n) {
	int pivotIndex = choosePivot(p, n);
	int pivotValue = arr[pivotIndex];
	swap(arr[pivotIndex], arr[n]);

	int piv = arr[n];
	int i = p - 1;
	for (int j = p; j <= n - 1; j++)
		if (arr[j] <= piv) {
			swap(arr[++i], arr[j]);
		}
	swap(arr[i + 1], arr[n]);
	return i + 1;
}

int choosePivot(int l, int h) {
	return l + (h - l) / 2;
}

void swap(int *x, int *y) {
	int tmp = *x;
	*x = *y;
	*y = tmp;
}