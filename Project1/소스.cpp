#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

vector<int> indeg;
vector<vector<int>> graph;
vector<int> cons;


int main() {
	fastio;
	int N, M, K;
	cin >> N >> M >> K;

	graph.resize(N + 1);
	indeg.resize(N + 1);
	cons.resize(N + 1);

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
		indeg[v]++;
	}

	queue<pii> command;
	for (int i = 0; i < K; i++) {
		int a, b;
		cin >> a >> b;
		command.push({ a, b });
	}

	while (!command.empty()) {
		int op = command.front().first;
		int n = command.front().second;
		command.pop();

		if (op == 1) {
			if (indeg[n] > 0) {
				cout << "Lier!" << endl;
				return 0;
			}
			else {
				cons[n]++;
				for (int i = 0; i < graph[n].size(); i++) {
					int next = graph[n][i];
					indeg[next]--;
				}
			}
		}

		if (op == 2) {
			if (cons[n] <= 0) {
				cout << "Lier!" << endl;
				return 0;
			}
			else {
				cons[n]--;
				for (int i = 0; i < graph[n].size(); i++) {
					int next = graph[n][i];
					indeg[next]++;
				}
			}
		}
	}

	cout << "King-God-Emperor";
	return 0;
}