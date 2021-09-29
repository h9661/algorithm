#include <bits/stdc++.h>
#pragma warning (disable : 4996)
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

pair<int, int> dp[40 + 1];

int main() {
	int tc;
	cin >> tc;

	dp[0].first = 1;
	dp[0].second = 0;

	dp[1].first = 0;
	dp[1].second = 1;

	for (int i = 2; i <= 40; i++) {
		dp[i].first = dp[i - 1].first + dp[i - 2].first;
		dp[i].second = dp[i - 1].second + dp[i - 2].second;
	}

	while (tc--) {
		int n;
		cin >> n;

		cout << dp[n].first << " " << dp[n].second << endl;
	}
}