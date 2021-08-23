#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

const int MAX = 10000 + 1;
const int INF = 2e9;
int dist[MAX];
vector<pii> graph[MAX];

void djk(int c) {
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	dist[c] = 0;
	pq.push({ 0, c });

	while (!pq.empty()) {
		int currentCost = pq.top().first;
		int currentNode = pq.top().second;
		pq.pop();

		for (int i = 0; i < graph[currentNode].size(); i++) {
			int nextCost = graph[currentNode][i].first;
			int nextNode = graph[currentNode][i].second;

			if (dist[nextNode] > dist[currentNode] + nextCost) {
				dist[nextNode] = dist[currentNode] + nextCost;
				pq.push({ nextCost, nextNode });
			}
		}
	}
}

int main() {
	fastio;
	int t;
	cin >> t;

	while (t--) {
		for (int i = 0; i < MAX; i++)
			graph[i].clear();
		fill(dist, dist + MAX, INF);

		int n, d, c;
		cin >> n >> d >> c;

		for (int i = 0; i < d; i++) {
			int from, to, val;
			cin >> to >> from >> val;

			graph[from].push_back({ val, to });
		}

		djk(c);

		int computer_count = 0;
		int time = 0;

		for (int i = 1; i <= n; i++) {
			if (dist[i] != INF) {
				computer_count++;

				if (dist[i] > time)
					time = dist[i];
			}
		}

		cout << computer_count << " " << time << endl;
	}
}