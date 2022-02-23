#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int sum = a[0];

	for (int i = 0; i < n; i++) {
		sum |= a[i];
	}

	cout << sum << endl;
}

int main() {
	int t;
	cin >> t;

	while (t--)
		solve();

	return 0;
}