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

const int MAX = 501;
bool check[MAX];
vector<int> graph[MAX];
int g_count = 0;

void bfs() {
	queue<pii> q;
	q.push({ 1, 2 });
	check[1] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int remain = q.front().second;
		q.pop();

		if (remain == 0)
			continue;

		for (int i = 0; i < graph[x].size(); i++) {
			int y = graph[x][i];

			if (check[y] == false) {
				q.push({ y, remain - 1 });
				check[y] = true;
				g_count++;
			}
		}
	}
}

int main() {
	fastio;
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	bfs();

	cout << g_count << endl;
}