#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;

	vector<int> a(n);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a.begin(), a.end());

	int score = accumulate(a.begin(), a.begin() + n - 2 * k, 0);
	
	for (int i = 0; i < k; i++) {
		score += floor(a[i + n - 2 * k] / a[i + n - k]);
	}

	cout << score << endl;
}

int main() {
	int t;
	cin >> t;

	while (t--)
		solve();

	return 0;
}