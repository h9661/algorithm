#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define ii pair<int, int>
using namespace std;

// 백준 14567
// 가장 기본적인 위상정렬 문제

vector<vector<int>> graph;
vector<int> indiag;
vector<int> dist;

int main() {
	int N, M;
	cin >> N >> M;

	graph.resize(N + 1);
	indiag.resize(N + 1);
	dist.resize(N + 1);

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
		indiag[v]++;
	}

	queue<int> q;

	for (int i = 1; i <= N; i++) {
		if (indiag[i] == 0)
			q.push(i);

		dist[i] = 1;
	}
	
	while (!q.empty()) {
		int currentNode = q.front();
		q.pop();

		for (int i = 0; i < graph[currentNode].size(); i++) {
			int nextNode = graph[currentNode][i];

			if (--indiag[nextNode] == 0)
				q.push(nextNode);

			if (dist[nextNode] < dist[currentNode] + 1)
				dist[nextNode] = dist[currentNode] + 1;
		}
	}

	for (int i = 1; i <= N; i++)
		cout << dist[i] << " ";

	return 0;
}