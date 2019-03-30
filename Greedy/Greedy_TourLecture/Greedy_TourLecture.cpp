#include <iostream>
#include <algorithm> 
#include <vector>
#include <queue>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	int p[10001], d[10001];
	vector<pair<int, int>> arr;
	for (int i = 0; i < n; i++) {
		cin >> p[i] >> d[i];
		arr.push_back(make_pair(d[i], p[i]));
	}
	sort(arr.begin(), arr.end());
	int max = 0;
	priority_queue<int> que;
	for (int i = 0; i < n; i++) {
		max += arr[i].second;
		que.push(-arr[i].second);
		if (que.size() > arr[i].first) {
			max += que.top();
			que.pop();
		}
	}
	printf("%d\n", max);
	return 0;
}