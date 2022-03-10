#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> a(n);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	int b, c;
	cin >> b >> c;

	long long ans = a.size();

	for (int i = 0; i < n; i++) {
		a[i] -= b;

		if (a[i] < 0)
			continue;
		else if (a[i] <= c && a[i] != 0)
			ans++;
		else {
			if (a[i] % c == 0)
				ans += a[i] / c;
			else
				ans += (a[i] / c) + 1;
		}
	}

	cout << ans << endl;
}