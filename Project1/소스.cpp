#include <bits/stdc++.h>
#define endl '\n'
#define ll pair<long long, long long>
#define ii pair<int, int>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long A, B;
	cin >> A >> B;

	queue<ll> q;
	q.push({ A, 0 });
	map<long long, bool> mp;

	while (!q.empty()) {
		long long curX = q.front().first;
		long long curC = q.front().second;
		q.pop();

		if (curX == B) {
			cout << curC + 1 << endl;
			return 0;
		}

		if (2 * curX <= B and mp[2 * curX] == false) {
			q.push({ 2 * curX, curC + 1 });
			mp[2 * curX] = true;
		}

		if (10 * curX + 1 <= B and mp[10 * curX + 1] == false) {
			q.push({ curX * 10 + 1, curC + 1 });
			mp[10 * curX + 1] = true;
		}
	}

	cout << -1 << endl;
}