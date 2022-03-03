#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		long long n, x;
		cin >> n >> x;
		map<long long, long long> m;

		vector<long long> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			m[a[i]]++;
		}

		sort(a.begin(), a.end());
		int ans = 0;

		for (int i = 0; i < n; i++) {
			if (m[a[i]] > 0) {
				if (m[a[i] * x] > 0) {
					m[a[i]]--;
					m[a[i] * x]--;
				}
				else {
					m[a[i]]--;
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
}