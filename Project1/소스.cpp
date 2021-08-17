#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define ii pair<ll, ll>
using namespace std;

int m, n;
const int MAX = 200000 + 1;
vector<ii> graph[MAX];
bool check[MAX];
ll ans = 0;

void prim() {
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	pq.push({ 0, 0 });

	while (!pq.empty()) {
		int currentCost = pq.top().first;
		int currentNode = pq.top().second;
		pq.pop();

		if (check[currentNode] == true)
			continue;

		check[currentNode] = true;
		ans += currentCost;

		for (int i = 0; i < graph[currentNode].size(); i++) {
			int nextCost = graph[currentNode][i].first;
			int nextNode = graph[currentNode][i].second;

			if (check[nextNode] == false)
				pq.push({ nextCost, nextNode });
		}
	}
}

int main() {
	while (1) {
		ans = 0;
		fill(check, check + MAX, false);
		for (int i = 0; i < MAX; i++)
			graph[i].clear();

		cin >> m >> n;

		if (m == 0 && n == 0)
			break;

		ll totalCost = 0;

		for (int i = 0; i < n; i++) {
			int from, to, val;
			cin >> from >> to >> val;

			graph[from].push_back({ val, to });
			graph[to].push_back({ val, from });
			totalCost += val;
		}

		prim();

		cout << totalCost - ans << endl;
	}
}