#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define ii pair<int, int>
using namespace std;

// backjoon 2086
// 2021 8 7
// 1. 행렬과 분할정복을 이용한 피보나치 수열 구하기

const int mod = 1000000000;
ull n1;
ull n2;

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

	n2 += 2;
	n1 += 1;

	vector<vector<ull>> ans1 = {
		{1, 0},
		{0, 1}
	};

	vector<vector<ull>> a1 = {
		{1, 1},
		{1, 0}
	};

	vector<vector<ull>> ans2 = {
		{1, 0},
		{0, 1}
	};

	vector<vector<ull>> a2 = {
		{1, 1},
		{1, 0}
	};

	while (n1 > 0) {
		if (n1 % 2 == 1)
			ans1 = multiple(ans1, a1);

		a1 = multiple(a1, a1);
		n1 /= 2;
	}

	while (n2 > 0) {
		if (n2 % 2 == 1)
			ans2 = multiple(ans2, a2);

		a2 = multiple(a2, a2);
		n2 /= 2;
	}

	cout << (((ans2[0][1] % mod - ans1[0][1] % mod)) + mod) % mod << endl;

	return 0;
}