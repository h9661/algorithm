#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define ii pair<int, int>
using namespace std;

// backjoon 11444 
// 2021 8 6
// 행렬과 분할정복을 이용한 피보나치 수열 구하기

const int mod = 1000000007;
ll n;

vector<vector<ll>> multiple(vector<vector<ll>>& a, vector<vector<ll>>& b) {
	vector<vector<ll>> c(2, vector<ll>(2));

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++)
				c[i][j] += a[i][k] * b[k][j];

			c[i][j] %= mod;
		}
	}

	return c;
}

int main() {
	cin >> n;

	vector<vector<ll>> ans = {
		{1, 0},
		{0, 1}
	};
	vector<vector<ll>> a = {
		{1, 1},
		{1, 0}
	};

	while (n > 0) {
		if (n % 2 == 1)
			ans = multiple(ans, a);

		a = multiple(a, a);
		n /= 2;
	}

	cout << ans[0][1] << endl;

	return 0;
}