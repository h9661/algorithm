#include <bits/stdc++.h>
#pragma warning (disable : 4996)
#pragma warning (disable : 6385)
#pragma warning (disable : 6386)
#pragma warning (disable : 6200)
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

	int X, Y;
	cin >> X >> Y;

	int ans = 0;

	if (X > Y) {
		ans += X;
		ans += Y;
		ans += Y / 10;
	}
	else {
		ans += Y;
		ans += X;
		ans += X / 10;
	}

	cout << ans << endl;
}