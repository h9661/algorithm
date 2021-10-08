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

ll dp[1000001];

int main() {
	int N;
	cin >> N;

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;

	for (int i = 4; i <= 1000000; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
	}

	cout << dp[N] << endl;

	return 0;
}