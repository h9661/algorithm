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
	string L, R;
	cin >> L >> R;

	if (L.size() != R.size())
		cout << 0 << endl;
	else {
		int count_8 = 0;

		for (int i = 0; i < L.size(); i++) {
			if (L[i] == R[i] && R[i] == '8')
				count_8++;
			else if(L[i] != R[i])
				break;
		}

		cout << count_8 << endl;
	}
}