#include <bits/stdc++.h>
#define endl '\n'
#define ll pair<long long, long long>
#define ii pair<int, int>
using namespace std;

const int MAX = 1001;
vector<int> graph[MAX];
bool check[MAX];

void bfs(int node) {
	queue<int> q;
	q.push(node);
	check[node] = true;

	while (!q.empty()) {
		int cn = q.front();
		q.pop();

		for (int i = 0; i < graph[cn].size(); i++) {
			int nn = graph[cn][i];
			
			if (check[nn] == false) {
				q.push(nn);
				check[nn] = true;
			}
		}
	}
}

int main() {
	int N, M;
	cin >> N >> M;
	int count = 0;
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= N; i++) {
		if (check[i] == false) {
			bfs(i);
			count++;
		}
	}

	cout << count << endl;
}