#include <bits/stdc++.h>
using namespace std;
/*
* 브루트포스는 안됨.......
* 
*/
int main() {
	int n;
	cin >> n;

	vector<pair<long long, long long>> parr(n);
	for (int i = 0; i < n; i++) {
		cin >> parr[i].first;
		cin >> parr[i].second;
	}

	sort(parr.begin(), parr.end(), [](pair<int, int> a, pair<int, int> b) {
		if (a.second == b.second)
			return a.first < b.first;
		else
			return a.second < b.second;
		});
	int i = 0;
	int answer = 0;
	long long end = parr[0].second;
	i++;
	answer++;

	while (i < parr.size()) {
		if (end <= parr[i].first) {
			answer++;
			end = parr[i].second;
		}

		i++;
	}
	cout << answer << endl;

	return 0;
}