#include<iostream>

#define N 3
#define Max 31

using namespace std;


void Greedy_Knapsack_Profit(int item[][2]) {

	int tmp = Max;
	int an=0;
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			if (item[i][0] < item[j][0]) swap(item[i], item[j]);
		}
	}
	
	for (int i = 0; i < N; i++) {
		if (tmp-item[i][1] >= 0) {
			tmp -= item[i][1];
			an += item[i][0];
		}
		else {
			cout << "Greedy_Knapsack_Profit" << endl;
			cout << an << endl;
		}
	}

}

void Greedy_Knapsack_Weight(int item[][2]) {
	int tmp = Max;
	int an = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			if (item[i][1] > item[j][1]) swap(item[i], item[j]);
		}
	}

	for (int i = 0; i < N; i++) {
		if (tmp - item[i][1] >= 0) {
			tmp -= item[i][1];
			an += item[i][0];
		}
		else {
			cout << "Greedy_Knapsack_Weight" << endl;
			cout << an << endl;
		}
	}
	


}

void Greedy_Knapsack_Density(int item[][2]) {
	int arr[N];
	int tmp = Max;
	int an = 0;

	for (int i = 0; i < N; i++) {
		arr[i] = item[i][0] / item[i][1];
	}

	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			if (arr[i] > arr[j]) swap(item[i], item[j]);
		}
	}

	for (int i = 0; i < N; i++) {
		if (tmp - item[i][1] >= 0) {
			tmp -= item[i][1];
			an += item[i][0];
		}
		else {
			cout << "Greedy_Knapsack_Density" << endl;
			cout << an << endl;
		}
	}


}

int main(void) {
	int item[N][2] = {50,5,60,10,140,20};
	
	Greedy_Knapsack_Profit(item);
	Greedy_Knapsack_Weight(item);
	Greedy_Knapsack_Density(item);
	

}



