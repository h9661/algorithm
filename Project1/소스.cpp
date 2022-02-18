#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 10000;
vector<int> arr(MAX_N + 1);
vector<int> dp(MAX_N + 1);

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	dp[0] = arr[0];
	dp[1] = arr[0] + arr[1];
	dp[2] = max(arr[0] + arr[2], arr[1] + arr[2]);
	for (int i = 3; i < n; i++) {

		dp[i] = max(*max_element(dp.begin(), dp.begin() + i - 2) + arr[i - 1] + arr[i], *max_element(dp.begin(), dp.begin() + i - 1) + arr[i]);
	}

	
	cout << *max_element(dp.begin(), dp.begin() + n) << endl;
}