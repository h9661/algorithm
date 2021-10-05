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

int main() {
	ll S;
	cin >> S;
	ll sum = 0;
	ll temp;

	for (ll i = 1; ; i++) {
		sum = i * (i + 1);

		if (sum > 2 * S) {
			temp = i;
			break;
		}
	}

	cout << temp - 1 << endl;

	return 0;
}