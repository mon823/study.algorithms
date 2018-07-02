#include<iostream>

using namespace std;

int main(void) {
	int n, arr[10000], tmp = 0;
	bool flag;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	for (int i = 0; i < n; i++) {
		flag = false;
		for (int j = 1; j < n - i; j++) {
			if (arr[j - 1] > arr[j]) {
				tmp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = tmp;
				flag = true;
			}
		}
		if (flag == false) break;
	}
	for (int i = 0; i<n; i++)
		printf("%d\n", arr[i]);
}