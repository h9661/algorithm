#include <bits/stdc++.h>
using namespace std;

void SolveTest() {
	int t, k;
	cin >> t >> k;

	string s;
	cin >> s;

	vector<int> cnt(26, 0);
	for (char c : s) {
		cnt[c - 'a']++;
	}

	int cntPairs = 0;
	int cntOdd = 0;

	for (int c : cnt) {
		cntPairs += c / 2;
		cntOdd += c % 2;
	}

	int ans = 2 * (cntPairs / k);
	cntOdd += 2 * (cntPairs % k);

	if (cntOdd >= k)
		ans += 1;
	
	cout << ans << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--)
		SolveTest();
}