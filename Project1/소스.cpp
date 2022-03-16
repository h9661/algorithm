#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

void solve() {
	long long m, p;
	cin >> m >> p;
	long long a, b;
	b = max(m, p);
	a = min(m, p);

	int ans = 0;

	if (3 * a <= b)
		ans = a;
	else
		ans = (a + b) / 4;

	cout << ans << endl;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}