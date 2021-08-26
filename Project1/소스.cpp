#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

int N, M;

const int MAX = 300 + 1;
int costs[MAX][MAX];
int dp[MAX][MAX];
int path[MAX][MAX];

int main() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		int n;
		cin >> n;

		for (int j = 1; j <= M; j++)
			cin >> costs[j][i];
	}

	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			if (dp[i - 1][j] < costs[i][j]) {
				dp[i][j] = costs[i][j];
				path[i][j] = j;
			}
			else {
				dp[i][j] = dp[i - 1][j];
				path[i][j] = 0;
			}

			int k = 1;
			while (k < j) {
				if (dp[i][j] < dp[i - 1][k] + costs[i][j - k]) {
					dp[i][j] = dp[i - 1][k] + costs[i][j - k];
					path[i][j] = j - k;
				}
				k++;
			}
		}
	}

	cout << dp[M][N] << endl;

	vector<int> store;
	int temp = path[M][N];
	int k = N;
	store.push_back(temp);

	for (int i = M - 1; i >= 1; i--) {
		k -= temp;
		temp = path[i][k];
		store.push_back(temp);
	}

	reverse(store.begin(), store.end());

	for (auto i : store)
		cout << i << " ";


	return 0;
}