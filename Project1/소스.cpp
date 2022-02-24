#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int count = 0;
	for (int i = 1; i < n - 1; i++) {
		if (i < n - 2) {
			if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
				a[i + 1] = max(a[i], a[i + 2]);
				count++;
			}
		}
		
		if (i == n - 2) {
			if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
				a[i + 1] = a[i];
				count++;
			}
		}
	}

	cout << count << endl;
	for (int i : a)
		cout << i << " ";
	cout << endl;
}

int main() {
	int t;
	cin >> t;

	while (t--)
		solve();

	return 0;
}