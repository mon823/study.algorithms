#include<iostream>

#define N 8

using namespace std;

struct Food{
	int food_value = 1;
	int food_cost = 2;
	int food_density = 3;
};

struct Menu{
	int value, Calorie;
	string name;
};

void  Greedy_Knapsack(Menu menu[],int max,int value) {

	struct Menu tmp[8];
	int temp = 0;
	int sum_value = 0;
	

	if (value == 1) {
		cout << "Use greedy by value to allocate" << endl;
		cout << max << " calories" << endl;
		
		for (int i = 0; i < N; i++) {
			for (int j = i; j < N; j++) {
				if (menu[i].value < menu[j].value) {
					swap(menu[i], menu[j]);
				}
			}
		}

		for (int i = 0; i < N; i++) {
			if (max - menu[i].Calorie >= 0) {
				max -= menu[i].Calorie;
				sum_value += menu[i].value;
				tmp[temp] = menu[i];
				temp++;
			}
		}
		
	}
	else if (value == 2) {
		cout << "Use greedy by calories to allocate" << endl;
		cout << max << " calories" << endl;


		for (int i = 0; i < N; i++) {
			for (int j = i; j < N; j++) {
				if (menu[i].Calorie < menu[j].Calorie) {
					swap(menu[i], menu[j]);
				}
			}
		}

		for (int i = 0; i < N; i++) {
			if (max - menu[i].Calorie >= 0) {
				max -= menu[i].Calorie;
				sum_value += menu[i].value;
				tmp[temp] = menu[i];
				temp++;
			}
		}

	}
	else if (value == 3) {
		cout << "Use greedy by density to allocate" << endl;
		cout << max << " calories" << endl;

		for (int i = 0; i < N; i++) {
			for (int j = i; j < N; j++) {
				if ((double)menu[i].Calorie/ (double)menu[i].value > (double)menu[j].Calorie/ (double)menu[j].value) {
					swap(menu[i], menu[j]);
				}
			}
		}

		for (int i = 0; i < N; i++) {
			if (max - menu[i].Calorie >= 0) {
				max -= menu[i].Calorie;
				sum_value += menu[i].value;
				tmp[temp] = menu[i];
				temp++;
			}
		}

	}
	cout << "Total value of items taken = " << sum_value << endl;

	for (int i = 0; i < temp; i++) {
		cout << "\t" << tmp[i].name << " : <" << tmp[i].value << ", " << tmp[i].Calorie << ">" << endl;
	}
}


int main(void) {
	// 초기화
	int food_info[N][2] = {
		{ 89,123 }, { 90,154 },{95,258},{100,354},{90,365},{79,150},{50,95},{10,195}
	};
	string food_Name[N] = { "Wine","Beer","Pizza","Burger","Fires","Coke","Apple","Donut" };

	struct Menu menu[N];

	for (int i = 0; i < N; i++) {
		menu[i].name = food_Name[i];
		menu[i].value = food_info[i][0];
		menu[i].Calorie = food_info[i][1];
	}

	//여기까지 초기화

	struct Food food;

	Greedy_Knapsack(menu, 750, food.food_value);
	cout << endl;
	Greedy_Knapsack(menu, 750, food.food_cost);
	cout << endl;
	Greedy_Knapsack(menu, 750, food.food_density);
	cout << endl;
	

}



