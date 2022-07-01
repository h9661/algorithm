#include <bits/stdc++.h>
#define endl '\n'
#define ll pair<long long, long long>
#define ii pair<int, int>
using namespace std;

int N, M;
bool check[101];

int main() {
	cin >> N >> M;

	map<int, int> warp;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;

		warp[x] = y;
	}
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;

		warp[u] = v;
	}

	queue<ii> q;
	q.push({ 1, 0 });
	check[1] = true;

	int ans = 199999;

	while (!q.empty()) {
		int curpos = q.front().first;
		int curCost = q.front().second;
		q.pop();

		if (curpos == 100)
			ans = min(ans, curCost);

		for (int i = 1; i <= 6; i++) {
			int nxtpos = curpos + i;
			int nxtcost = curCost + 1;

			if (nxtpos <= 100 and check[nxtpos] == false) {
				check[nxtpos] = true;
				if (warp[nxtpos] != 0) {
					q.push({ warp[nxtpos], nxtcost });
					check[warp[nxtpos]] = true;
				}
				else
					q.push({ nxtpos, nxtcost });
			}
		}
	}
	
	cout << ans << endl;
}