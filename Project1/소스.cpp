#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define ii pair<int, int>
using namespace std;

// 백준 1516
// 위상 정렬

vector<vector<int>> graph;
vector<int> costs;
vector<int> dist;
vector<int> indiag;

int main() {
	int N;
	cin >> N;

	graph.resize(N + 1);
	costs.resize(N + 1);
	dist.resize(N + 1);
	indiag.resize(N + 1);

	for (int i = 1; i <= N; i++) {
		cin >> costs[i];

		while (1) {
			int temp;
			cin >> temp;

			if (temp == -1)
				break;

			graph[temp].push_back(i);
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

			if (dist[nextNode] < dist[currentNode] + costs[nextNode]) {
				dist[nextNode] = dist[currentNode] + costs[nextNode];
				q.push(nextNode);
			}
		}
	}

	for (int i = 1; i <= N; i++)
		cout << dist[i] << endl;

	return 0;
}