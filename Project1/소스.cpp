#include <bits/stdc++.h>
using namespace std;

void solve() {
	string s;
	char c;
	cin >> s >> c;

	vector<pair<int, int>> count;
	int countLeft = 0;

	for (int i = 0; i < s.size(); i++) {
		if (i == 0 && s[i] == c || i == s.size() - 1 && s[i] == c) {
			cout << "YES" << endl;
			return;
		}

		if (s[i] == c) {
			count.push_back({ countLeft, s.size() - countLeft - 1 });
		}

		countLeft++;
	}

	for (auto i : count) {
		if (i.first % 2 == 0 && i.second % 2 == 0) {
			cout << "YES" << endl;
			return;
		}
	}

	cout << "NO" << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}