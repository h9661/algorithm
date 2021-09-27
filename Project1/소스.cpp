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
	getline(cin, s);

	vector<char> temp;

	int k = 0;
	int count = 0;
	while (k < s.size()) {
		if (count == 10) {
			count = 0;
			for (auto i : temp)
				cout << i;
			cout << endl;
			temp.clear();
		}
		temp.push_back(s[k]);
		k++;
		count++;
	}

	for (auto i : temp)
		cout << i;
	
	return 0;
}