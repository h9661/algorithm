#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

bool check[1001];

void dfs(int N, int V, vector<vector<int>> graph) {
	cout << V << " ";
	check[V] = true;
	for (int i = 0; i < graph[V].size(); i++) {
		if (check[graph[V][i]] == false) {
			check[graph[V][i]] = true;
			dfs(N, graph[V][i], graph);
		}
	}
}

void bfs(int N, int V, vector<vector<int>> graph) {
	vector<bool> check(N + 1, false);
	queue<int> que;

	que.push(V);
	check[V] = true;

	while (!que.empty()) {
		int curNode = que.front();
		cout << curNode << " ";
		que.pop();

		for (int i = 0; i < graph[curNode].size(); i++) {
			int nxtNode = graph[curNode][i];

			if (check[nxtNode] == false) {
				que.push(nxtNode);
				check[nxtNode] = true;
			}
		}
	}
	cout << endl;
}

int main() {
	int N, M, V;
	cin >> N >> M >> V;

	vector<vector<int>> graph(N + 1);

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}


	for (int i = 1; i <= N; i++){
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(N, V, graph);
	cout << endl;
	bfs(N, V, graph);
}