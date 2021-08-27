#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

int N, M;
int start, des;
const int MAX = 10000 + 1;
vector<pii> graph[MAX];
bool check[MAX];

bool bfs(int limit) {
	fill(check, check + MAX, false);
	queue<pii> q;
	q.push({ 0, start });
	check[start] = true;

	while (!q.empty()) {
		int weight = q.front().first;
		int node = q.front().second;
		q.pop();

		if (node == des)
			return true;

		for (int i = 0; i < graph[node].size(); i++) {
			int nextWeight = graph[node][i].first;
			int nextNode = graph[node][i].second;

			if (check[nextNode] == false && limit <= nextWeight) {
				check[nextNode] = true;
				q.push({ nextWeight, nextNode });
			}
		}
	}

	return false;
}

int bin_search(int maxWeight) {
	int left = 0;
	int right = maxWeight;

	while (left <= right) {
		int center = (left + right) / 2;

		bool flag = bfs(center);

		if (flag == true)
			left = center + 1;
		else
			right = center - 1;
	}

	return right;
}

int main() {
	cin >> N >> M;
	int maxWeight = 0;
	
	for (int i = 0; i < M; i++) {
		int u, v, weight;
		cin >> u >> v >> weight;

		graph[u].push_back({ weight, v });
		graph[v].push_back({ weight, u });
		
		if (maxWeight < weight)
			maxWeight = weight;
	}
	cin >> start >> des;

	cout << bin_search(maxWeight) << endl;

	return 0;
}