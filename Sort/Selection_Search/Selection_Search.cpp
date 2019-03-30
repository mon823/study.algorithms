#include <iostream>

using namespace std;

int partition(int *arr, int p, int n);
int select(int * arr, int  p, int  r, int k);

void swap(int *x, int *y);


int arr[1000];

int main(void)
{
	int n;
	int k;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	scanf("%d", &k);
	printf("%d ", select(arr, 1, n, k));
}

int partition(int *arr, int p, int n) {

	int piv = arr[n];
	int i = p - 1;
	for (int j = p; j <= n - 1; j++)
		if (arr[j] <= piv) {
			swap(arr[++i], arr[j]);
		}
	swap(arr[i + 1], arr[n]);
	return i + 1;
}

void swap(int *x, int *y) {
	int tmp = *x;
	*x = *y;
	*y = tmp;
}


int select(int * arr, int  p, int  n, int k) {
	if (p == n) return arr[p];
	int q;
	q = partition(arr, p, n);
	int kk = q - p + 1;
	if (kk < k)
		return select(arr, p, q - 1, k);
	else if (kk == k)
		return arr[q];
	else
		return select(arr, p, q - 1, k);

}