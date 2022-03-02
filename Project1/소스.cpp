#include <bits/stdc++.h>
using namespace std;

void solve() {
	pair<int, int> p1;
	pair<int, int> p2;
	pair<int, int> p3;

	cin >> p1.first; cin >> p1.second;
	cin >> p2.first; cin >> p2.second;
	cin >> p3.first; cin >> p3.second;

	if (p1.second == p2.second && p1.second > p3.second)
		cout << abs(p1.first - p2.first) << endl;
	else if (p1.second == p3.second && p1.second > p2.second)
		cout << abs(p1.first - p3.first) << endl;
	else if (p2.second == p3.second && p2.second > p1.second)
		cout << abs(p2.first - p3.first) << endl;
	else
		cout << "0" << endl;
}

int main() {
	int t;
	cin >> t;

	while (t--)
		solve();

	return 0;
}