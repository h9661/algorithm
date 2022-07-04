#include <bits/stdc++.h>
#define endl '\n'
#define ll pair<long long, long long>
#define ii pair<int, int>
using namespace std;

const int MAX = 1000;
int dp[MAX][3];
int arr[MAX][3];

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}
	
	dp[0][0] = arr[0][0];
	dp[0][1] = arr[0][1];
	dp[0][2] = arr[0][2];

	for (int i = 1; i < n; i++) {
		dp[i][0] = min(arr[i][0] + dp[i - 1][1], arr[i][0] + dp[i - 1][2]);
		dp[i][1] = min(arr[i][1] + dp[i - 1][0], arr[i][1] + dp[i - 1][2]);
		dp[i][2] = min(arr[i][2] + dp[i - 1][0], arr[i][2] + dp[i - 1][1]);
	}

	cout << min(min(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]) << endl;
}