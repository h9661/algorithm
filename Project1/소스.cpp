#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;

	vector<long long> a(n);
	int count = 0;


	for (int i = 0; i < n; i++)
		cin >> a[i];

	if (a[n - 2] > a[n - 1]) {
		cout << -1 << endl;
		return;
	}
	else {
		if (a[n - 1] >= 0) {
			for (int i = 0; i < n - 2; i++) {
				a[i] = a[n - 2] - a[n - 1];
				count++;
			}
			
			cout << count << endl;
			for (int i = 1; i <= n - 2; i++)
				cout << i << " " << n - 1 << " " << n << endl;
		}
		else {
			if (is_sorted(a.begin(), a.end(), [](long long a, long long b) {
				return a < b;
				})) {
				cout << count << endl;
			}
			else
				cout << -1 << endl;
		}
	}
}

int main() {
	int t;
	cin >> t;

	while (t--)
		solve();

	return 0;
}