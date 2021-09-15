#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

const int MAX = 800 + 1;
const int INF = 987654321;

vector<int> graph[MAX];
int parent[MAX];
int capacity[MAX][MAX];
int flow[MAX][MAX];

int maxFlow(int source, int sink) {
	int total_flow = 0;
	int start = source, des = sink;
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
	
	const int OUT = 400;

	for (int i = 1; i <= N; i++) {
		graph[i].push_back(i + OUT);
		graph[i + OUT].push_back(i);

		capacity[i][i + OUT] = 1;
	}

	for (int i = 0; i < P; i++) {
		int u, v;
		cin >> u >> v;

		graph[u + OUT].push_back(v);
		graph[v].push_back(u + OUT);

		graph[v + OUT].push_back(u);
		graph[u].push_back(v + OUT);

		capacity[u + OUT][v] += 1;
		capacity[v + OUT][u] += 1;
	}

	int start = 401;
	int des = 2;


	cout << maxFlow(start, des) << endl;


	return 0;
}