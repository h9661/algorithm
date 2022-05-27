#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int dp[5001];
const int INF = 1e9;

int main() {
	int N;
	cin >> N;

	dp[1] = INF;
	dp[2] = INF;
	dp[3] = 1;
	dp[4] = INF;
	dp[5] = 1;


	for (int i = 6; i <= 5000; i++) {
		dp[i] = min(dp[i - 3] + 1, dp[i - 5] + 1);
	}

	if (dp[N] >= 1e8)
		cout << -1 << endl;
	else
		cout << dp[N] << endl;
}