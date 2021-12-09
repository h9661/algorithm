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
	while (1) {
		int a, b;
		cin >> a >> b;

		if (a == 0 and b == 0)
			break;

		if (b % a == 0 && a < b)
			cout << "factor" << endl;
		else if (a % b == 0 && a > b)
			cout << "multiple" << endl;
		else
			cout << "neither" << endl;
	}

	return 0;
}