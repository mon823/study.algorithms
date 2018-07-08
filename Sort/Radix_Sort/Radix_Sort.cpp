#include <iostream>
#include <queue>

using namespace std;

int arr[1000000];

int main(void)
{
	queue<int> radix[10];
	int n;
	int max = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		if (max < arr[i])
			max = arr[i];
	}

	int k;
	for (k = 1; max > 0; k*=10) {
		max /= 10;
	}
	k /= 10;
	int m = 10;
	for (int min = 1; min <= k; min *= 10){
		for (int i = 0; i < n; i++) {
			radix[(arr[i] % m) / min].push(arr[i]);
		}
		for (int i = 0, j = 0; i < 10;) {
			if (radix[i].size()) {
				arr[j++] = radix[i].front();
				radix[i].pop();
			}
			else i++;
		}
		m *= 10;
	}
	for (int i = 0; i < n; i++)
		printf("%d\n", arr[i]);
}
