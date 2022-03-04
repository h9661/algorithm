#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;

	vector<int> even;
	vector<int> odd;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		if (x % 2 == 0)
			even.push_back(x);
		else
			odd.push_back(x);
	}

	bool check = false;

	if (is_sorted(even.begin(), even.end()) && is_sorted(odd.begin(), odd.end()))
		check = true;
	
	if (check)
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