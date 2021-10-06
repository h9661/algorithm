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
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);

	int count = 0;

	int i = 0;
	while (i < s1.size()) {
		bool flag = false;
		int temp = i;

		for (int j = 0; j < s2.size(); j++) {
			if (s1[temp] != s2[j])
				break;
			else
				temp++;

			if (j == s2.size() - 1) {
				count++;
				flag = true;
			}
		}

		if (flag)
			i += s2.size();
		else
			i++;
	}

	cout << count << endl;
}