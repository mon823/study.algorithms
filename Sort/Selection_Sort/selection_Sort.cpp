#include<iostream>

using namespace std;

void selectionSort(int *arr, int n);

int main(void) {
	int n, arr[10000], tmp = 0;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	selectionSort(arr, n);

	for (int i = 0; i<n; i++)
		printf("%d\n", arr[i]);
}

void selectionSort(int *arr, int n) {
	int i, j;
	int min, tmp;
	for (i = 0; i < n - 1; i++) {
		min = i;
		for (j = i + 1; j < n; j++) {
			if (arr[j] < arr[min]) min = j;
		}
		tmp = arr[i];
		arr[i] = arr[min];
		arr[min] = tmp;
	}
}