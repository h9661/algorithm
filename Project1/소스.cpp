#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

const int MAX = 1000 + 1;
int I[MAX];
int T[MAX];
int dp[1001][10001];

int main() {
	int N, K;
	cin >> N >> K;

	for (int i = 1; i <= K; i++) {
		cin >> I[i] >> T[i];
	}

	for (int i = 1; i <= K; i++) {
		for (int j = 1; j <= N; j++) {
			if (j - T[i] >= 0) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - T[i]] + I[i]);
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j]);
			}
		}
	}

	cout << dp[K][N] << endl;
}