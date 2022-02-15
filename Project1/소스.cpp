#include <bits/stdc++.h>
using namespace std;


void solve() {
	int n, m;
	cin >> n >> m;

	map<string, bool> have;
	map<string, tuple<int, int, int>> pos;
	vector<bool> dp(m + 1, false);
	vector<int> pr(m + 1);

	dp[0] = true;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < m; j++) {
			string t;
			t += s[j];

			for (int k = 1; k <= 2; k++) {
				if (k + j >= m)
					break;

				t += s[j + k];

				if (have[t] == false) {
					have[t] = true;
					pos[t] = make_tuple(j, j + k, i);
				}
			}
		}
	}

	string s;
	cin >> s;

	for (int i = 0; i < m; i++) {
		string t;
		t += s[i];

		for (int k = 1; k <= 2; k++) {
			if (i - k < 0)
				break;
			
			t = s[i - k] + t;

			if (have[t] && dp[i - k]) {
				dp[i + 1] = true;
				pr[i + 1] = i - k;
			}
			if (dp[i + 1])
				break;
		}
	}

	if (dp[m] == false) {
		cout << "-1" << endl;
		return;
	}

	vector<tuple<int, int, int>> ans;
	
	for (int k = m; k > 0;) {
		int p = pr[k];
		string t = s.substr(p, k - p);
		ans.push_back(pos[t]);
		k = p;
	}

	reverse(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		cout << get<0>(ans[i]) + 1 << ' ' << get<1>(ans[i]) + 1 << ' ' << get<2>(ans[i]) + 1 << endl;
	}
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}