#include<iostream>

using namespace std;

void insertionSort(int *arr, int n);

int main(void) {
	int n, arr[10000], tmp = 0;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	insertionSort(arr, n);

	for (int i = 0; i<n; i++)
		printf("%d\n", arr[i]);
}

void insertionSort(int *arr, int n) {
	int i, j, k;
	int key;

	for (int i = 1; i < n; i++) {
		key = arr[i];
		k = i;
		for (j = i - 1; j >= 0; --j) {
			if (key < arr[j]) {
				arr[j + 1] = arr[j];
				k = j;
			}
		}
		arr[k] = key;
	}
}