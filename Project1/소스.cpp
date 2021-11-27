#include <bits/stdc++.h>
#pragma warning (disable : 4996)
#pragma warning (disable : 6385)
#pragma warning (disable : 6386)
#pragma warning (disable : 6200)
#pragma warning (disable : 26812)
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

int dp[51][51][51];

ll w(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;
	else if (a > 20 || b > 20 || c > 20) {
		if (!dp[20][20][20])
			dp[20][20][20] = w(20, 20, 20);

		return dp[20][20][20];
	}
	else if (a < b and b < c) {
		if (!dp[a][b][c - 1])
			dp[a][b][c - 1] = w(a, b, c - 1);
		if (!dp[a][b - 1][c - 1])
			dp[a][b - 1][c - 1] = w(a, b - 1, c - 1);
		if (!dp[a][b - 1][c])
			dp[a][b - 1][c] = w(a, b - 1, c);

		return dp[a][b][c - 1] + dp[a][b - 1][c - 1] - dp[a][b - 1][c];
	}
	else {
		if (!dp[a - 1][b][c])
			dp[a - 1][b][c] = w(a - 1, b, c);
		if (!dp[a - 1][b - 1][c])
			dp[a - 1][b - 1][c] = w(a - 1, b - 1, c);
		if (!dp[a - 1][b - 1][c - 1])
			dp[a - 1][b - 1][c - 1] = w(a - 1, b - 1, c - 1);

		return dp[a - 1][b][c] + dp[a - 1][b - 1][c] + w(a - 1, b, c - 1) - dp[a - 1][b - 1][c - 1];
	}
}

int main() {
	while (1) {
		int a, b, c;
		cin >> a >> b >> c;

		if (a == -1 and b == -1 and c == -1)
			break;

		printf("w(%d, %d, %d) = ", a, b, c);
		cout << w(a, b, c) << endl;
	}
}