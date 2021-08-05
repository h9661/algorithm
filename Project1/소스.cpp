#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define ii pair<int, int>
using namespace std;

const int MAX = 100 + 1;
vector<ii> val_cost_pair;
int val[MAX];
int cost[MAX];
int dp[MAX][100001];

bool cmp(ii a, ii b) {
	if (a.second != b.second)
		return a.second < b.second;
	else
		return a.first > b.first;
}

int main() {
	int N, M;
	cin >> N >> M;

	val_cost_pair.push_back({ 0, 0 });

	for (int i = 1; i <= N; i++)
		cin >> val[i];

	for (int i = 1; i <= N; i++)
		cin >> cost[i];

	for (int i = 1; i <= N; i++)
		val_cost_pair.push_back({ val[i], cost[i] });


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= 10001; j++) {
			if (j - val_cost_pair[i].second >= 0)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - val_cost_pair[i].second] + val_cost_pair[i].first);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	for (int j = 1; j <= 10001; j++) {
		for (int i = 1; i <= N; i++) {
			if (dp[i][j] >= M) {
				cout << j << endl;
				return 0;
			}
		}
	}

	return 0;
}