#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int INF = 1e9;

int main() {
	int N, M;
	cin >> N >> M;

	vector<vector<int>> graph(N + 1, vector<int>(N + 1, INF));
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;

		graph[u][v] = 1;
		graph[v][u] = 1;
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (graph[i][k] + graph[k][j] < graph[i][j])
					graph[i][j] = graph[i][k] + graph[k][j];
			}
		}
	}

	vector<pair<int, int>> answer;

	for (int i = 1; i <= N; i++) {
		int sum = 0;
		for (int j = 1; j <= N; j++) {
			if (i == j)
				continue;
			sum += graph[i][j];
		}
		answer.push_back({ i, sum });
	}

	sort(answer.begin(), answer.end(), [](pair<int, int> a, pair<int, int> b) {
		return a.second < b.second;
		});

	cout << answer[0].first << endl;
}