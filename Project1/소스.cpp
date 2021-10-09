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

	while (1) {
		string s;
		cin >> s;

		if (s == "0")
			break;

		int count = 0;

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '1')
				count += 2;
			else if (s[i] == '0')
				count += 4;
			else
				count += 3;

			count += 1;
		}

		cout << count + 1<< endl;
	}
}