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

int main() {
	string s;
	getline(cin, s);

	char strArr[5] = { 'U', 'C', 'P', 'C', '\0' };
	int count = 0;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == strArr[count])
			count++;
	}

	if (count == 4)
		cout << "I love UCPC" << endl;
	else
		cout << "I hate UCPC" << endl;
}