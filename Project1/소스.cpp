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

const int MAX = 90 + 1;
ll dp[MAX];
int N;

int main() {
	cin >> N;

	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 2;

	for (int i = 4; i <= 90; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	cout << dp[N] << endl;

	return 0;
}