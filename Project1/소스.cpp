#include <bits/stdc++.h>
using namespace std;

string my_reverse(string str) {
	string retStr = str;
	for (int i = 0; i < retStr.size() / 2; i++) {
		char temp = retStr[retStr.size() - i - 1];
		retStr[retStr.size() - i - 1] = retStr[i];
		retStr[i] = temp;
	}

	return retStr;
}

void solve() {
	int n, k;
	cin >> n >> k;

	string s;
	cin >> s;

	if (n % 2 == 0) {
		if (s.substr(0, n / 2) == my_reverse(s.substr(n / 2, 5555555))) {
			cout << 1 << endl;
		}
		else {
			if (k >= 1)
				cout << 2 << endl;
			else
				cout << 1 << endl;
		}
	}
	else {
		if (s.substr(0, n / 2) == my_reverse(s.substr(n / 2 + 1, 5555555))) {
			cout << 1 << endl;
		}
		else {
			if (k >= 1)
				cout << 2 << endl;
			else
				cout << 1 << endl;
		}
	}
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}