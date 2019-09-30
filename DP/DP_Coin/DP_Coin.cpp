#include<iostream>

using namespace std;

void dp_coin() {
	int arr[4] = { 1,4,5,6 };
	int arr_change[1000] = { 0, };
	int money;
	int num = 0;
	int tmp;


	scanf_s("%d", &money);

	for (int i = 1; i <= money; i++) {
		arr_change[i] = 987654321;
	}
	

	for (int i = 0; i < 4; i++) {
		for (int j = arr[i]; j <= money; j++) {
			tmp = j - arr[i];
			if (tmp >= 0) {
				if (arr_change[j] > (arr_change[tmp]  + 1)) {
					arr_change[j] = arr_change[tmp] + 1;
				}
			}
		}
	}
	cout << arr_change[money] << endl;
	
}

int main(void) {
	dp_coin();
}