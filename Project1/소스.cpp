#include <bits/stdc++.h>
using namespace std;

vector<string> subseqs = { "00", "25", "50", "75" };

int solve(string s, string t) {
	int sptr = s.size() - 1;
	int ans = 0;

	while (sptr >= 0 && s[sptr] != t[1]) {
		sptr--;
		ans++;
	}
	if (sptr < 0)
		return 100;

	sptr--;

	while (sptr >= 0 && s[sptr] != t[0]) {
		sptr--;
		ans++;
	}
	if (sptr < 0)
		return 100;
	else
		return ans;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		string n;
		cin >> n;

		int ans = 100;
		for (auto e : subseqs)
			ans = min(ans, solve(n, e));

		cout << ans << endl;
	}
}