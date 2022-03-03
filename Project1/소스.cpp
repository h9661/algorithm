#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;

	vector<int> a(n + 1, 0);
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	int start, end;
	for (int i = 1; i <= n; i++) {
		if (a[i] != i) {
			start = i;

			for (int j = start; j <= n; j++) {
				if (start == a[j]) {
					end = j;
					reverse(a.begin() + start, a.begin() + end + 1);
					break;
				}
			}
			break;
		}
	}

	for (int i = 1; i <= n; i++)
		cout << a[i] << " ";
	cout << endl;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}