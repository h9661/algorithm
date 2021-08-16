#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define ii pair<int, int>
using namespace std;

const int MAX = 400 + 1;
const int INF = 1e9;
int V, E;
int graph[MAX][MAX];

int main() {
	cin >> V >> E;

	fill(&graph[0][0], &graph[MAX - 1][MAX], INF);

	for (int i = 0; i < E; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;

		graph[from][to] = cost;
	}

	for (int k = 1; k <= V; k++) {
		for (int i = 1; i <= V; i++) {
			for (int j = 1; j <= V; j++) {
				if (graph[i][j] > graph[i][k] + graph[k][j])
					graph[i][j] = graph[i][k] + graph[k][j];
			}
		}
	}
	int ans = INF;

	for (int i = 1; i <= V; i++) {
		if (ans > graph[i][i])
			ans = graph[i][i];
	}

	if (ans == INF)
		cout << "-1" << endl;
	else
		cout << ans << endl;

	return 0;
}