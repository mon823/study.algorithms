#include<iostream>

using namespace std;

int tmp[10000];
int temp = 0;

void Counting_Sort(int * arr, int n);
void Count_Sum(int *arr, int n);

int main() {
	int n;
	int input;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &input);

		tmp[input]++;
		if (input > temp)
			temp = input;
	}

	Counting_Sort(tmp, n);

}

void Counting_Sort(int * arr, int n) {
	Count_Sum(arr, n);
	for (int i = 1; i <= temp; i++) {
		int index = arr[i] - arr[i - 1];
		if (i == 1)
			index = arr[i];
		while (index--) {
			printf("%d\n", i);
		}
	}
	
}

void Count_Sum(int *arr, int n) {
	int sum = 0;
	for (int i = 1; i <= temp; i++) {
		tmp[i] += tmp[i - 1];
	}
}
