#include <bits/stdc++.h>
using namespace std;

void solve() {
	string s;
	cin >> s;

	if (s.size() % 2 == 1)
		cout << "NO" << endl;
	else if (s.substr(0, s.size() / 2) == s.substr(s.size() / 2, string::npos))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}

int main() {
	int t;
	cin >> t;
	
	while (t--) {
		solve();
	}
}