#include <bits/stdc++.h>
#define endl '\n'
#define ll pair<long long, long long>
#define ii pair<int, int>
using namespace std;

int dp[50001];

int main() {
	map<string, string> mp;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string site, password;
		cin >> site >> password;

		mp[site] = password;
	}

	for (int i = 0; i < m; i++) {
		string site;
		cin >> site;

		cout << mp[site] << endl;
	}
}