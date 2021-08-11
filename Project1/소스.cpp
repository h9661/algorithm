#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define ii pair<int, int>
using namespace std;

// 백준 2056
// 위상 정렬

vector<vector<int>> graph;
vector<int> dist;
vector<int> costs;
vector<int> indiag;

int main() {
	fastio;
	int N;
	cin >> N;

	graph.resize(N + 1);
	dist.resize(N + 1);
	costs.resize(N + 1);
	indiag.resize(N + 1);

	for (int i = 1; i <= N; i++) {
		cin >> costs[i];

		int num;
		cin >> num;

		for (int j = 0; j < num; j++) {
			int u;
			cin >> u;

			graph[u].push_back(i);
			indiag[i]++;
		}
	}

	queue<int> q;

	for (int i = 1; i <= N; i++) {
		if (indiag[i] == 0) {
			q.push(i);
			dist[i] = costs[i];
		}
	}

	while (!q.empty()) {
		int currentNode = q.front();
		q.pop();

		for (int i = 0; i < graph[currentNode].size(); i++) {
			int nextNode = graph[currentNode][i];

			if (--indiag[nextNode] == 0)
				q.push(nextNode);

			if (dist[nextNode] < dist[currentNode] + costs[nextNode])
				dist[nextNode] = dist[currentNode] + costs[nextNode];
		}
	}

	cout << *max_element(dist.begin(), dist.end()) << endl;

	return 0;
}