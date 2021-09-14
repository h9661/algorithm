#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

const int MAX = 400 + 1;
const int INF = 987654321;

vector<int> graph[MAX];
int parent[MAX];
int capacity[MAX][MAX];
int flow[MAX][MAX];

int maxFlow(int start, int des) {
	int total_flow = 0;

	while (1) {
		fill(parent, parent + MAX, -1);
		queue<int> q;
		q.push(start);
		parent[start] = start;

		while (!q.empty()) {
			int x = q.front();
			q.pop();

			for (int i = 0; i < graph[x].size(); i++) {
				int y = graph[x][i];

				if (capacity[x][y] - flow[x][y] > 0 && parent[y] == -1) {
					q.push(y);
					parent[y] = x;

					if (y == des)
						break;
				}
			}
		}

		if (parent[des] == -1)
			break;

		int amount = INF;
		for (int i = des; i != start; i = parent[i])
			amount = min(capacity[parent[i]][i] - flow[parent[i]][i], amount);

		for (int i = des; i != start; i = parent[i]) {
			flow[parent[i]][i] += amount;
			flow[i][parent[i]] -= amount;
		}

		total_flow += amount;
	}

	return total_flow;
}

int main() {
	int N, P;
	cin >> N >> P;

	for (int i = 0; i < P; i++) {
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);

		capacity[u][v] += 1;
	}

	int start = 1;
	int des = 2;


	cout << maxFlow(start, des) << endl;


	return 0;
}