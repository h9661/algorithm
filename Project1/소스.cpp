#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define ii pair<int, int>
using namespace std;

// 백준 2252
// 위상 정렬
// 우선순위 큐로 가장 높은 우선순위 먼저 내보내기

vector<vector<int>> graph;
vector<int> indiag;

int main() {
	int N, M;
	cin >> N >> M;

	graph.resize(N + 1);
	indiag.resize(N + 1);

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
		indiag[v]++;
	}

	priority_queue<int, vector<int>, less<>> q;
	
	for (int i = N; i >= 1; i--) {
		if (indiag[i] == 0)
			q.push(i);
	}

	while (!q.empty()) {
		int currentNode = q.top();

		q.pop();

		if (indiag[currentNode] == 0)
			cout << currentNode << " ";

		for (int i = 0; i < graph[currentNode].size(); i++) {
			int nextNode = graph[currentNode][i];

			if (--indiag[nextNode] == 0)
				q.push(nextNode);
		}
	}

	return 0;
}