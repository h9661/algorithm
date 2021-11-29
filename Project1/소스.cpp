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

const int MAX = 10001;
vector<int> graph[MAX];
bool check[MAX];

int bfs(int i) {
	int count = 0;
	queue<int> q;
	
	q.push(i);
	check[i] = true;
	count++;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < graph[cur].size(); i++) {
			int nxt = graph[cur][i];

			if (check[nxt] == false) {
				check[nxt] = true;
				count++;
				q.push(nxt);
			}
		}
	}
	
	return count;
}

bool cmp(pii a, pii b) {
	if (a.first == b.first)
		return a.second < b.second;
	else
		return a.first > b.first;
}

int main() {
	fastio;
	vector<int> store;
	vector<pii> save;
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;

		graph[v].push_back(u);
	}

	int maximum = -1;

	for (int i = 1; i <= N; i++) {
		int count = bfs(i);
		maximum = max(maximum, count);
		save.push_back({ count, i });
		fill(check, check + MAX, false);
	}

	for (int i = 0; i < save.size(); i++) {
		if (save[i].first == maximum)
			store.push_back(save[i].second);
	}
	sort(store.begin(), store.end());

	for (int i = 0; i < store.size(); i++)
		cout << store[i] << " ";


	return 0;
}