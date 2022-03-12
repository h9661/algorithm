#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

void solve() {
	int l, r, a;
	cin >> l >> r >> a;

	int k = r - r % a - 1;

	if (k >= l)
		cout << max(r / a + r % a, k / a + k % a) << endl;
	else
		cout << r / a + r % a << endl;
}

int main() {
	int t;
	cin >> t;
	
	while (t--) {
		solve();
	}
}