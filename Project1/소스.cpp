#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

#define zero first
#define one second

int main() {
	int T;
	cin >> T;

	vector<pair<int, int>> dp(41);
	dp[0].zero = 1;
	dp[0].one = 0;

	dp[1].zero = 0;
	dp[1].one = 1;

	for (int i = 2; i <= 40; i++) {
		dp[i].zero = dp[i - 1].zero + dp[i - 2].zero;
		dp[i].one = dp[i - 1].one + dp[i - 2].one;
	}


	while (T--) {
		int n;
		cin >> n;

		cout << dp[n].zero << " " << dp[n].one << endl;
	}
}