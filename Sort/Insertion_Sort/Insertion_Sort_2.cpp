#include<iostream>

using namespace std;

void insertionSort(int *arr, int n);

int main(void) {
	int n, arr[10000];
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);

	insertionSort(arr, n);

	for (int i = 1; i <= n; i++)
		printf("%d\n", arr[i]);
}

void insertionSort(int *arr, int n) {
	int k;
	int loc;
	int newItem;
	for (int i = 2; i <= n; i++) {
		loc = i - 1;
		newItem = arr[i];
		while (loc >= 1 && newItem < arr[loc]) {
			arr[loc + 1] = arr[loc];
			loc = loc - 1;
		}
		arr[loc + 1] = newItem;
	}
}