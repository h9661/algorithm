#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define ii pair<int, int>
using namespace std;

const int MAX = 10000 + 1;
vector<ii> graph[MAX];
bool check[MAX];
ll ans = 0;
int V, E;

void prim(int start) {
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	pq.push({ 0, start });

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

	cout << ans << endl;
}

int main() {
	cin >> V >> E;
	
	for (int i = 0; i < E; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;

		graph[from].push_back({ cost, to });
		graph[to].push_back({ cost, from });
	}

	prim(1);

	return 0;
}