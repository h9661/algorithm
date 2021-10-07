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
	string s;
	cin >> s;
	int count_1 = 0;
	bool flag_1 = true;
	int count_0 = 0;
	bool flag_0 = true;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '1' and flag_1 == true) {
			count_1++;
			flag_1 = false;
		}

		if (s[i] == '0' and flag_0 == true) {
			count_0++;
			flag_0 = false;
		}
		
		if (s[i] == '0')
			flag_1 = true;

		if (s[i] == '1')
			flag_0 = true;
	}

	if (count_0 < count_1)
		cout << count_0 << endl;
	else
		cout << count_1 << endl;
}