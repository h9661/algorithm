#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

void solve() {
	string s;
	cin >> s;

	int ans = 0;

	if (s.size() == 1) {
		if ((s[0] - '0') % 2 == 0)
			ans = 0;
		else
			ans = -1;
	}
	else {
		if ((s[s.size() - 1] - '0') % 2 == 0)
			ans = 0;
		else {
			if ((s[0] - '0') % 2 == 0)
				ans = 1;
			else {
				bool check = false;

				for (int i = 1; i < s.size() - 1; i++) {
					if ((s[i] - '0') % 2 == 0) {
						check = true;
						break;
					}
				}

				if (check)
					ans = 2;
				else
					ans = -1;
			}
		}
	}

	cout << ans << endl;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}