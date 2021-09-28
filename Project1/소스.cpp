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
	bool flag = true;
	int count = 0;

	for (int i = 0; i < 8; i++) {
		string s;
		getline(cin, s);

		for (int j = 0; j < 8; j++) {
			if (flag) {
				if (s[j] == 'F')
					count++;
			}

			flag = !flag;
		}

		flag = !flag;
	}

	cout << count << endl;
}