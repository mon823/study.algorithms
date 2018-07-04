#include<iostream>

using namespace std;

void merge(int * arr, int p, int q, int  n);
void mergeSort(int *arr, int p, int n);

int main(void) {
	int n, arr[1000000], tmp = 0;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	mergeSort(arr,0, n-1);

	for (int i = 0; i<n; i++)
		printf("%d\n", arr[i]);
}

void mergeSort(int *arr, int p, int n) {
	int q;
	if (p < n) {
		q = (p + n) / 2;
		mergeSort(arr, p, q);
		mergeSort(arr, q + 1, n);
		merge(arr, p, q, n);
	}
	return;
}

void merge(int * arr, int p, int q, int  n) {
	int i = p;
	int j = q + 1;
	int t = 0;
	int tmp[1000000];

	while (i <= q && j <= n) {
		if (arr[i] <= arr[j]) {
			tmp[t++] = arr[i++];
		}
		else {
			tmp[t++] = arr[j++];
		}
	}
	while (i <= q) {
		tmp[t++] = arr[i++];
	}
	while (j <= n) {
		tmp[t++] = arr[j++];
	}
	i = p;
	t = 0;
	while (i <= n) {
		arr[i++] = tmp[t++];
	}
}