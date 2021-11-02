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

const ll mod = 1000000007;

ll pow_mod(ll a, ll b){
	ll ret = 1;

	while (b) {
		if (b % 2) {
			ret *= a;
			ret %= mod;
		}

		a = ((a * a) % mod);
		b /= 2;
	}

	return ret;
}

int main() {
	int M;
	cin >> M;

	ll sum = 0;

	while (M--) {
		ll a, b;
		cin >> b >> a;

		ll temp = pow_mod(b, mod - 2);
		sum += ((a % mod) * (temp % mod)) % mod;
		sum %= mod;
	}

	cout << sum % mod << endl;
}