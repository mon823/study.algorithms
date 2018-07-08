#include <iostream>
#include <queue>

using namespace std;

int arr[1000];

int main(void)
{
	queue<int> radix[20];
	int n;
	int max = 0;
	int min = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);

		if (max < arr[i])
			max = arr[i];
		if (min > arr[i])
			min = arr[i];
	}
	int k;
	for (k = 1; max > 0; k *= 10) {
		max /= 10;
	}
	k /= 10;

	max = min * -1;
	int k_1;
	for (k_1 = 1; max > 0; k_1 *= 10) {
		max /= 10;
	}
	k_1 /= 10;

	if (k_1 > k)
		k = k_1;

	int m = 10;
	for (int min = 1; min <= k; min *= 10) {
		int tmp;
		for (int i = 0; i < n; i++) {
			tmp = (arr[i] % m) / min;
			if (tmp < 0) {
				tmp *= -1;
				tmp = 10 - tmp;
			}
			else tmp += 10;
			radix[tmp].push(arr[i]);
		}
		for (int i = 0, j = 0; i < 20;) {
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
