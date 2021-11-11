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

int main() {
	fastio;

	int N, K;
	cin >> N >> K;

	int temp = (K * (K + 1)) / 2;
	N -= temp;

	if (N < 0)
		cout << -1 << endl;
	else {
		if (N % K == 0)
			cout << K - 1 << endl;
		else
			cout << K << endl;
	}
}