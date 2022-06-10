#include <bits/stdc++.h>
#define endl '\n'
#define ii pair<long long, long long>
using namespace std;

int dp[10010];

int main() {
	int N;
	cin >> N;

	vector<int> score(N, 0);

	for (int i = 0; i < N; i++)
		cin >> score[i];

	dp[0] = score[0];
	dp[1] = dp[0] + score[1];
	dp[2] = max(dp[0] + score[2], score[1] + score[2]);

	for (int i = 3; i < N; i++) {
		dp[i] = max(dp[i - 2] + score[i], dp[i - 3] + score[i - 1] + score[i]);
	}

	cout << dp[N - 1] << endl;
}