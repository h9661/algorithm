#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define ii pair<int, int>
using namespace std;

int memo[1000001];
int track[1000001];

int dp(int N) {
	if (N == 1)
		return 0;
	if (memo[N])
		return memo[N];

	int count = dp(N - 1) + 1;
	track[N] = N - 1;

	if (N % 3 == 0) {
		int temp = min(count, dp(N / 3) + 1);
		if (temp < count) {
			count = temp;
			track[N] = N / 3;
		}
	}

	if (N % 2 == 0) {
		int temp = min(count, dp(N / 2) + 1);
		if (temp < count) {
			count = temp;
			track[N] = N / 2;
		}
	}

	memo[N] = count;

	return memo[N];
}

int main() {
	memo[1] = 0;
	track[1] = -1;

	int N;
	cin >> N;

	cout << dp(N) << endl;

	while (N != -1) {
		cout << N << " ";
		N = track[N];
	}

	return 0;
}