#include<iostream>

#define N 3
#define Max 31

using namespace std;


void DP_Knapsack(int item[][2]) {
	int back[Max] = { 0, };
	

	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			if (item[i][0] > item[j][0]) swap(item[i], item[j]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < Max; j++) {
			if (j - item[i][1] >= 0 && j - item[i][1] < item[i][1]) {
				if (back[j] < back[j - item[i][1]] + item[i][0]) {
					back[j] = back[j - item[i][1]] + item[i][0];
				}
			}
		}

	}

	cout << "DP_Knapsack" << endl;

	cout << back[30] << endl;


}

int main(void) {
	int item[N][2] = {50,5,60,10,140,20};

	DP_Knapsack(item);

}



