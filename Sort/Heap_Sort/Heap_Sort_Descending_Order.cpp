#include<iostream>

using namespace std;

int A[1000001];
void buildHeap(int *arr, int n);
void heapify(int *arr, int k, int n);
void heapSort(int *arr, int n);
void swap(int *x, int *y);

int main() {
	int n;

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &A[i]);
	}

	heapSort(A, n);

	for (int i = 1; i <= n; i++) {
		printf("%d\n", A[i]);
	}
}
void swap(int *x, int *y) {
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

void heapSort(int *arr, int n) {
	int tmp;
	buildHeap(arr, n);
	for (int i = n; i >= 2; i--) {
		swap(arr[1], arr[i]);
		heapify(arr, 1, i - 1);
	}
}

void buildHeap(int *arr, int n) {
	for (int i = n / 2; i >= 1; i--)
		heapify(arr, i, n);
}

void heapify(int *arr, int k, int n) {
	int smaller;
	int left = 2*k;
	int right = 2*k + 1;
	if (right <= n) {
		if (arr[left] < arr[right])
			smaller = left;
		else
			smaller = right;
	}
	else if (left <= n)
		smaller = left;
	else return;
	if (arr[smaller] < arr[k]) {
		swap(arr[k], arr[smaller]);
		heapify(arr, smaller, n);
	}

}