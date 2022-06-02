#include <bits/stdc++.h>
#define endl '\n'
using namespace std;


int main() {
	int N;
	cin >> N;

	vector<int> dp(1000001, 1000000);

	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	for (int i = 4; i <= 1000000; i++) {
		if (i % 3 == 0)
			dp[i] = min(dp[i], dp[i / 3] + 1);

		if (i % 2 == 0)
			dp[i] = min(dp[i], dp[i / 2] + 1);

		dp[i] = min(dp[i], dp[i - 1] + 1);
	}

	cout << dp[N] << endl;
}