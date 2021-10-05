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
	ll A, B;
	cin >> A >> B;

	queue<pll> q;

	q.push({ A, 1 });

	while (!q.empty()) {
		ll x = q.front().first;
		ll count = q.front().second;
		q.pop();

		if (x == B) {
			cout << count << endl;
			return 0;
		}

		if (x * 2 <= B) {
			q.push({ x * 2, count + 1 });
		}

		if ( (x * 10 + 1) <= B) {
			q.push({ x * 10 + 1, count + 1 });
		}
	}

	cout << -1 << endl;
}