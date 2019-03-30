#include <iostream>
#include <algorithm> 
#include <vector>

using namespace std;

int main(void) {
	int n;
	cin >> n;
	int arrStart[100001], arrEnd[100001];
	vector<pair<int, int>> arr;
	for (int i = 0; i < n; i++) {

		scanf("%d %d", &arrStart[i], &arrEnd[i]);
		arr.push_back(make_pair(arrEnd[i], arrStart[i]));
	}
	sort(arr.begin(), arr.end());

	int start = 0, sum = 0;
	for (int i = 0; i < arr.size(); i++) {
		if (start <= arr[i].second) {
			start = arr[i].first;
			sum++;
		}
	}
	printf("%d", sum);
	return 0;
}