#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define ii pair<int, int>
using namespace std;

const int MAX = 100000 + 1;
vector<ii> graph[MAX];
bool check[MAX];
int ans = 0;
int lastValue = 0;
int N, M;

void prim() {
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	pq.push({ 0, 1 });

	while (!pq.empty()) {
		int currentCost = pq.top().first;
		int currentNode = pq.top().second;
		pq.pop();

		if (check[currentNode] == true)
			continue;

		check[currentNode] = true;
		ans += currentCost;
		lastValue = max(currentCost, lastValue);

		for (int i = 0; i < graph[currentNode].size(); i++) {
			int nextCost = graph[currentNode][i].first;
			int nextNode = graph[currentNode][i].second;

			if (check[nextNode] == false)
				pq.push({ nextCost, nextNode });
		}
	}
}

int main() {
	fastio;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;

		graph[from].push_back({ cost, to });
		graph[to].push_back({ cost, from });
	}

	prim();

	cout << ans - lastValue << endl;

	return 0;
}