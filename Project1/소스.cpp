#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

const int MAX = 1000 + 1;
vector<pair<double, int>> graph[MAX];
pair<int, int> coordinate[MAX];
bool check[MAX];
int N, M;

double FindDistance(double x1, double y1, double x2, double y2) {
	double dx = (x2 - x1) * (x2 - x1);
	double dy = (y2 - y1) * (y2 - y1);

	return sqrt(dx + dy);
}

int main() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		int u, v;
		cin >> u >> v;

		coordinate[i].first = u;
		coordinate[i].second = v;
	}

	for (int i = 1; i <= M; i++) {
		int u, v;
		cin >> u >> v;

		graph[u].push_back({ 0.0, v });
		graph[v].push_back({ 0.0, u });
	}

	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			double dist = FindDistance(coordinate[i].first, coordinate[i].second, coordinate[j].first, coordinate[j].second);

			graph[i].push_back({ dist, j });
			graph[j].push_back({ dist, i });
		}
	}

	priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
	pq.push({ 0.0, 1 });

	double ans = 0;

	while (!pq.empty()) {
		double currentCost = pq.top().first;
		int currentNode = pq.top().second;
		pq.pop();

		if (check[currentNode] == true)
			continue;

		check[currentNode] = true;
		ans += currentCost;

		for (int i = 0; i < graph[currentNode].size(); i++) {
			double nextCost = graph[currentNode][i].first;
			int nextNode = graph[currentNode][i].second;

			if (check[nextNode] == false) 
				pq.push({ nextCost, nextNode });
		}
	}

	cout << fixed;
	cout.precision(2);

	cout << ans << endl;
}