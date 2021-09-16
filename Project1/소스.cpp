#include <bits/stdc++.h>
#pragma warning (disable : 4996)
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

const int MAX = 10000 + 1;
const int INF = 987654321;

vector<short> graph[MAX];
vector<short> path[100];
bool capacity[MAX][MAX];
bool flow[MAX][MAX];
short parent[MAX];
int g_count = 0;

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

			if(i < 5000)
				path[g_count].push_back(i);
		}

		g_count++;
		total_flow += amount;
	}

	return total_flow;
}

int main() {
	int tt = 1;

	while (1) {
		cin.clear();
		for (int i = 0; i < MAX; i++)
			graph[i].clear();

		for (int i = 0; i < 100; i++)
			path[i].clear();

		fill(&capacity[0][0], &capacity[MAX - 1][MAX], 0);
		fill(&flow[0][0], &flow[MAX - 1][MAX], 0);
		g_count = 0;

		int K, N;
		cin >> K >> N;

		if (K == 0 && N == 0)
			break;

		const int OUT = 5000;
		const int IN = 0;

		for (int i = 1; i <= N; i++) {
			graph[i + IN].push_back(i + OUT);
			graph[i + OUT].push_back(i + IN);

			capacity[i + IN][i + OUT] = 1;
		}

		for (int i = 1; i <= N; i++) {
			short input[5001];
			int idx = 0;
			char temp;

			while (1) {
				scanf("%d%c", &input[idx++], &temp);
				if (temp == '\n')
					break;
			}

			for (int j = 0; j < idx; j++) {
				int to = input[j];

				graph[i + OUT].push_back(to + IN);
				graph[to + IN].push_back(i + OUT);

				capacity[i + OUT][to + IN] = 1;
				capacity[to + OUT][i + IN] = 1;
			}
		}


		cout << "Case " << tt << ":" << endl;

		int start = 5001;
		int des = 2;

		int numOfPath = maxFlow(start, des);

		if (K == g_count) {
			for (int i = 0; i < g_count; i++) {
				cout << 1 << " ";

				for (int j = path[i].size() - 1; j >= 0; j--) {
					cout << path[i][j] << " ";
				}
				cout << endl;
			}
		}
		else {
			cout << "Impossible" << endl;
		}
		cout << endl;

		tt++;
	}
	return 0;
}