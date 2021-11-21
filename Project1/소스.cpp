#include <bits/stdc++.h>
#pragma warning (disable : 4996)
#pragma warning (disable : 6385)
#pragma warning (disable : 6386)
#pragma warning (disable : 6200)
#pragma warning (disable : 26812)
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

int main() {
	int tc;
	cin >> tc;

	while (tc--) {
		int N, M;
		cin >> N >> M;

		vector<int> graph[1001];
		bool check[1001];
		fill(check, check + 1001, false);

		for (int i = 0; i < M; i++) {
			int a, b;
			cin >> a >> b;

			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		int ans = 0;
		queue<int> q;
		q.push(1);
		check[1] = true;

		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			for (int i = 0; i < graph[cur].size(); i++) {
				int nxt = graph[cur][i];
				
				if (check[nxt] == false) {
					check[nxt] = true;
					ans++;
					q.push(nxt);
				}
			}
		}

		cout << ans << endl;
	}
}