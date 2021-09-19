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

//10830

const int MAX = 5 + 1;
const int mod = 1000;
ll N, B;

vector<vector<ull>> multiple(vector<vector<ull>>& a, vector<vector<ull>>& b) {
	vector<vector<ull>> retval(MAX, vector<ull>(MAX, 0));

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++)
				retval[i][j] += a[i][k] * b[k][j];
			retval[i][j] %= mod;
		}
	}

	return retval;
}


int main() {
	cin >> N >> B;

	vector<vector<ull>> E(MAX, vector<ull>(MAX, 0));

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j)
				E[i][j] = 1;
		}
	}

	vector<vector<ull>> A(MAX, vector<ull>(MAX, 0));

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			cin >> A[i][j];
	}

	while (B > 0) {
		if (B % 2 == 1) {
			E = multiple(E, A);
		}

		A = multiple(A, A);
		B /= 2;
	}

	if (B == 1) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cout << E[i][j] << " ";
			}
			cout << endl;
		}
	}
	else {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cout << E[i][j] % 1000 << " ";
			}
			cout << endl;
		}
	}
}