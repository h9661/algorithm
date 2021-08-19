#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

const int MAX = 15 + 1;
int dp[MAX];
int timeArr[MAX];
int priceArr[MAX];

int main() {
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> timeArr[i] >> priceArr[i];
		dp[i] = priceArr[i];
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 1; j < i; j++) {
			if (timeArr[j] + j <= i) {
				dp[i] = max(priceArr[i] + dp[j], dp[i]);
			}
		}
	}

	int ans = 0;

	for (int i = 1; i <= N; i++) {
		if (i + timeArr[i] - 1 <= N) {
			if (ans < dp[i])
				ans = dp[i];
		}
	}

	cout << ans << endl;

	return 0;
}