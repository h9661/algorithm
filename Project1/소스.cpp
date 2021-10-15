#include <bits/stdc++.h>
#pragma warning (disable : 4996)
#pragma warning (disable : 6385)
#pragma warning (disable : 6386)
#pragma warning (disable : 6200)
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

int dp[1001];

int main() {
	fastio;
	int N;
	cin >> N;

	dp[1] = 1;
	dp[2] = 0;
	dp[3] = 1;
	dp[4] = 1;

	for (int i = 5; i <= 1000; i++) {
		if (!dp[i - 1] || !dp[i - 3] || !dp[i - 4])
			dp[i] = 1;
		else
			dp[i] = 0;
	}

	if (dp[N] == 1)
		cout << "SK" << endl;
	else
		cout << "CY" << endl;

	return 0;
}