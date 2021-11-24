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

	int k = 1;
	int ans = 0;

	while (1) {
		int bottle_number = 0;
		int q = N / 2;
		int r = N % 2;

		while (q >= 1) {
			if(q % 2 == 1)
				bottle_number += 1;
			q /= 2;
		}
		bottle_number += 1;
		
		if (bottle_number <= K)
			break;
		else {
			N /= 2;

			if (r == 1) {
				ans += k;
				N += 1;
			}

			k *= 2;
		}
	}

	cout << ans << endl;
}