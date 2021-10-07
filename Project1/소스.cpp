#include <bits/stdc++.h>
#pragma warning (disable : 4996)
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

const int MAX = 100000 + 1;
int arr[MAX];
int dp[MAX];

int main() {
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	dp[N] = arr[N];

	for (int i = N - 1; i >= 1; i--)
		dp[i] = max(arr[i], arr[i] + dp[i + 1]);

	int ans = -987654321;

	for (int i = 1; i <= N; i++) {
		if (dp[i] > ans)
			ans = dp[i];
	}

	cout << ans << endl;
	
}