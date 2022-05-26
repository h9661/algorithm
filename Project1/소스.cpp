#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> coordinate;
	
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		coordinate.push_back({ x, y });
	}

	sort(coordinate.begin(), coordinate.end(), [](pair<int, int> a, pair<int, int> b) {
		if (a.first != b.first)
			return a.first < b.first;
		else
			return a.second < b.second;
		});

	for (auto i : coordinate)
		cout << i.first << " " << i.second << endl;
}