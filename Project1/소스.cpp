#include <bits/stdc++.h>
#define endl '\n'
#define ll pair<long long, long long>
#define ii pair<int, int>
using namespace std;

int dp[1001];

int main() {
	dp[1] = 1;
	dp[2] = 2;
	
	for (int i = 3; i <= 1000; i++)
		dp[i] = (dp[i - 1] % 10007 + dp[i - 2] % 10007) % 10007;

	int n;
	cin >> n;

	cout << dp[n] << endl;
}