#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define ii pair<int, int>
using namespace std;

// backjoon 11778
// 2021 8 6
// 1. 행렬과 분할정복을 이용한 피보나치 수열 구하기
// 2. 유클리드 호제법을 이용한 최대 공약수 구하기

const int mod = 1000000007;
ull n1;
ull n2;

ull gcd(ull a, ull b) {
	if (b == 0)
		return a;
	else
		return gcd((b), (a % b));
}

vector<vector<ull>> multiple(vector<vector<ull>>& a, vector<vector<ull>>& b) {
	vector<vector<ull>> c(2, vector<ull>(2));

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++)
				c[i][j] += (((a[i][k]) % mod) * ((b[k][j]) % mod)) % mod;
		}
	}

	return c;
}

int main() {
	fastio;
	cin >> n1 >> n2;

	ull temp = gcd(n1, n2);

	vector<vector<ull>> ans1 = {
		{1, 0},
		{0, 1}
	};

	vector<vector<ull>> a1 = {
		{1, 1},
		{1, 0}
	};


	while (temp > 0) {
		if (temp % 2 == 1)
			ans1 = multiple(ans1, a1);

		a1 = multiple(a1, a1);
		temp /= 2;
	}

	cout << ans1[0][1] % mod << endl;

	return 0;
}