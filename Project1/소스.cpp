#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<pair<int, int>> dp(41);
		dp[0].first = 1;
		dp[1].second = 0;

		dp[1].first = 0;
		dp[1].second = 1;

		for (int i = 2; i <= 40; i++) {
			dp[i].first = dp[i - 1].first + dp[i - 2].first;
			dp[i].second = dp[i - 1].second + dp[i - 2].second;
		}

		cout << dp[n].first << " " << dp[n].second << endl;
	}
}