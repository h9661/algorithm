#include <bits/stdc++.h>
#define endl '\n'
#define ll pair<long long, long long>
#define ii pair<int, int>
using namespace std;

const int MAX = 801;
vector<ii> graph[MAX];
const int INF = 50000000;
vector<long long> dist(MAX, INF);

struct cmp {
	bool operator()(ii a, ii b) {
		return a.second > b.second;
	}
};

int djk(int source, int target) {
	priority_queue<ii, vector<ii>, cmp> pq;
	pq.push({ source, 0 });
	dist[source] = 0;

	while (!pq.empty()) {
		int cn = pq.top().first;
		int cc = pq.top().second;
		pq.pop();

		if (cn == target)
			return dist[cn];

		for (int i = 0; i < graph[cn].size(); i++) {
			int nn = graph[cn][i].first;
			int nc = graph[cn][i].second;

			if (dist[nn] > dist[cn] + nc) {
				dist[nn] = dist[cn] + nc;
				pq.push({ nn, dist[nn]});
			}
		}
	}

	return INF;
}

int main() {
	int N, E;
	cin >> N >> E;

	for (int i = 0; i < E; i++) {
		int u, v, c;
		cin >> u >> v >> c;

		graph[u].push_back({ v, c });
		graph[v].push_back({ u, c });
	}

	int v1, v2;
	cin >> v1 >> v2;

	long long sum1 = 0;
	sum1 += djk(1, v1);
	fill(dist.begin(), dist.end(), INF);
	sum1 += djk(v1, v2);
	fill(dist.begin(), dist.end(), INF);
	sum1 += djk(v2, N);
	fill(dist.begin(), dist.end(), INF);

	long long sum2 = 0;
	sum2 += djk(1, v2);
	fill(dist.begin(), dist.end(), INF);
	sum2 += djk(v2, v1);
	fill(dist.begin(), dist.end(), INF);
	sum2 += djk(v1, N);

	long long ans = min(sum1, sum2);

	if (ans >= 40000000)
		cout << -1 << endl;
	else
		cout << ans << endl;
}