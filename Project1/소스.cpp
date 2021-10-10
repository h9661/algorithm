#include <bits/stdc++.h>
#pragma warning (disable : 4996)
#pragma warning (disable : 6385)
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

int cost[21];
int value[21];
int dp[100001];

int main() {
	int C, N;
	cin >> C >> N;

	for (int i = 1; i <= N; i++)
		cin >> cost[i] >> value[i];

	for (int i = 1; i <= N; i++) {
		for (int j = cost[i]; j <= 100001; j++)
			dp[j] = max(dp[j], dp[j - cost[i]] + value[i]);
	}

	for (int i = 1; i <= 100001; i++) {
		if (dp[i] >= C) {
			cout << i << endl;
			return 0;
		}
	}
}