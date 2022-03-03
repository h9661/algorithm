#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;

	map<int, int> d;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		d[x]++;
	}

	int cnt = 0;
	for (auto i : d)
		cnt++;

	for (int k = 1; k <= n; k++)
		cout << max(k, cnt) << " ";
	cout << endl;
}

int main() {
	int t;
	cin >> t;

	while (t--)
		solve();

	return 0;
}