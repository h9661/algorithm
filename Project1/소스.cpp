#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define ii pair<int, int>
using namespace std;

// น้มุ 14728 kanpsack dp ps 2021 8 6

const int MAX = 101;
int N, T;
int cost[MAX];
int value[MAX];
int dp[MAX][10001];

int main() {
	cin >> N >> T;

	for (int i = 1; i <= N; i++) {
		cin >> cost[i];
		cin >> value[i];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= T; j++) {
			if (j - cost[i] >= 0)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - cost[i]] + value[i]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	cout << dp[N][T] << endl;
}