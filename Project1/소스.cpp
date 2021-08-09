#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define ii pair<int, int>
using namespace std;

// 백준 11779
// 다익스트라 알고리즘
// 최단거리 찾고 방문 노드 추적하기

int V, E, start, destination;
const int MAX = 1000 + 1;
const int INF = 987654321;
vector<ii> graph[MAX];
int dist[MAX];
int route[MAX];

void djk() {
	priority_queue<ii> pq;
	pq.push({ 0, start });
	dist[start] = 0;

	while (!pq.empty()) {
		int currentCost = -pq.top().first;
		int currentNode = pq.top().second;
		pq.pop();

		if (dist[currentNode] < currentCost)
			continue;

		for (int i = 0; i < graph[currentNode].size(); i++) {
			int nextCost = graph[currentNode][i].first + currentCost;
			int nextNode = graph[currentNode][i].second;

			if (dist[nextNode] > nextCost) {
				dist[nextNode] = nextCost;
				route[nextNode] = currentNode;
				pq.push({ -nextCost, nextNode });
			}
		}
	}
}

int main() {
	fastio;
	cin >> V;
	cin >> E;

	fill(dist, dist + MAX, INF);

	for (int i = 0; i < E; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;

		graph[from].push_back({ cost, to });
	}

	cin >> start >> destination;

	djk();

	cout << dist[destination] << endl;

	vector<int> ans;
	int node = destination;

	while (node) {
		ans.push_back(node);
		node = route[node];
	}

	cout << ans.size() << endl;

	for (int i = ans.size() - 1; i >= 0; i--)
		cout << ans[i] << " ";


	return 0;
}