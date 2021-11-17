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

const int MAX = 300000 + 1;
int N, M, K, X;
vector<int> graph[MAX];
int dist[MAX];

void bfs(int X) {
	queue<int> q;
	q.push({ X });
	dist[X] = 0;

	while (!q.empty()) {
		int curNode = q.front();

		q.pop();

		for (int i = 0; i < graph[curNode].size(); i++) {
			int nextNode = graph[curNode][i];

			if (dist[nextNode] > dist[curNode] + 1) {
				dist[nextNode] = dist[curNode] + 1;
				q.push(nextNode);
			}
		}
	}
}

int main() {
	fastio;
	cin >> N >> M >> K >> X;
	fill(dist, dist + MAX, 2e9);

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
	}

	bfs(X);

	vector<int> ans;

	for (int i = 1; i <= N; i++) {
		if (dist[i] == K)
			ans.push_back(i);
	}

	sort(ans.begin(), ans.end());

	if (ans.empty())
		cout << -1 << endl;
	else {
		for (auto i : ans)
			cout << i << endl;
	}
}