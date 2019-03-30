#include<iostream>
#include <algorithm> 
#include <queue>

using namespace std;

int main(void) {
	int n, k;
	int arr[10];
	int num = 0;
	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = n-1; i >= 0; i--) {
		for (;;) {
			if (k - arr[i] >= 0) {
				k -= arr[i];
				num++;
			}
			else break;
		}
	}
	printf("%d", num);

	return 0;
}