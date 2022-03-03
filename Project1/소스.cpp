#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> a(n + 1, 0);
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	vector<int> dp(n + 1, 0);

	dp[1] = a[1];

	for (int i = 2; i <= n; i++) {
		dp[i] = a[i];

		for (int j = 1; j <= i / 2; j++) {
			dp[i] = max(dp[j] + dp[i - j], dp[i]);
		}
	}

	cout << dp[n] << endl;

	return 0;
}