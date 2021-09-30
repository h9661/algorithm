#include <bits/stdc++.h>
#pragma warning (disable : 4996)
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

		vector<int> times(N + 1, 0);
		vector<int> costs(N + 1, 0);
		vector<int> indeg(N + 1, 0);
		vector<vector<int>> graph(N + 1);

		for (int i = 1; i <= N; i++)
			cin >> times[i];

		for (int i = 0; i < M; i++) {
			int from, to;
			cin >> from >> to;

			graph[from].push_back(to);
			indeg[to]++;
		}

		int W;
		cin >> W;

		queue<int> q;

		for (int i = 1; i <= N; i++) {
			if (indeg[i] == 0) {
				q.push(i);
				costs[i] = times[i];
			}
		}

		while (!q.empty()) {
			int curNode = q.front();
			int curCost = costs[curNode];
			q.pop();

			for (int i = 0; i < graph[curNode].size(); i++) {
				int nextNode = graph[curNode][i];
				int nextCost = times[nextNode] + curCost;

				if (--indeg[nextNode] == 0)
					q.push(nextNode);

				if (costs[nextNode] < nextCost)
					costs[nextNode] = nextCost;
			}
		}

		cout << costs[W] << endl;
	}
}