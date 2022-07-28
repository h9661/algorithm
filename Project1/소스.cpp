#include <bits/stdc++.h>
#define endl '\n'
#define ll pair<long long, long long>
#define ii pair<int, int>
using namespace std;

const int MAX = 10001;
vector<ll> graph[MAX];
bool check[MAX];

struct cmp {
	bool operator()(ll a, ll b) {
		return a.second > b.second;
	}
};

int prim() {
	long long retval = 0;
	priority_queue<ll, vector<ll>, cmp> min_heap;
	min_heap.push({ 1, 0 });

	while (!min_heap.empty()) {
		long long curNode = min_heap.top().first;
		long long curCost = min_heap.top().second;
		min_heap.pop();

		if (check[curNode] == true)
			continue;
		check[curNode] = true;
		retval += curCost;


		for (int i = 0; i < graph[curNode].size(); i++) {
			int nextNode = graph[curNode][i].first;
			int nextCost = graph[curNode][i].second;

			min_heap.push({ nextNode, nextCost });
		}
	}

	return retval;
}

int main() {
	int V, E;
	cin >> V >> E;

	for (int i = 0; i < E; i++) {
		int u, v, c;
		cin >> u >> v >> c;

		graph[u].push_back({ v, c });
		graph[v].push_back({ u, c });
	}

	cout << prim() << endl;
}