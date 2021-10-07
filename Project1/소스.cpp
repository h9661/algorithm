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
	int i = 1;
	while (i) {
		int L, P, V;
		cin >> L >> P >> V;

		if (L == 0 and P == 0 and V == 0)
			break;

		int count = 0;
		count += (V / P) * L;
		count += (V % P) > L ? L : (V % P);

		cout << "Case " << i << ": ";
		cout << count << endl;

		i++;
	}
}