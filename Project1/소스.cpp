#include <bits/stdc++.h>
#pragma warning (disable : 4996)
#pragma warning (disable : 6385)
#pragma warning (disable : 6386)
#pragma warning (disable : 6200)
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

const int MAX = 50 + 2;
int graph[MAX][MAX];
const int INF = 2e5;

int main() {
	fill(&graph[0][0], &graph[MAX - 1][MAX], INF);
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j)
				graph[i][j] = 0;
		}
	}


	while (1) {
		int u, v;
		cin >> u >> v;

		if (u == -1 and v == -1)
			break;

		graph[u][v] = 1;
		graph[v][u] = 1;
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (graph[i][j] > graph[i][k] + graph[k][j])
					graph[i][j] = graph[i][k] + graph[k][j];
			}
		}
	}

	vector<int> store(N + 1, 0);

	for (int i = 1; i <= N; i++) {
		int maximum = 0;

		for (int j = 1; j <= N; j++) {
			if (graph[i][j] > maximum)
				maximum = graph[i][j];
		}

		store[i] = maximum;
	}

	int min_num = *min_element(store.begin() + 1, store.end());
	int count = 0;
	vector<int> people;
	for (int i = 1; i <= N; i++) {
		if (min_num == store[i]) {
			count++;
			people.push_back(i);
		}
	}

	cout << min_num << " " << count << endl;
	for (auto i : people)
		cout << i << " ";

	return 0;
}