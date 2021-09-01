#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

const int MAX = 100 + 1;
vector<pair<double, double>> coord;
vector<pair<double, int>> graph[MAX];
bool check[MAX];

double FindDistance(double x1, double y1, double x2, double y2) {
	double dx = (x2 - x1) * (x2 - x1);
	double dy = (y2 - y1) * (y2 - y1);
	return sqrt(dx + dy);
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		double a, b;
		cin >> a >> b;
		coord.push_back({ a, b });
	}

	for (int i = 0; i < n; i++) {
		double x1 = coord[i].first;
		double y1 = coord[i].second;

		for (int j = i + 1; j < n; j++) {
			double x2 = coord[j].first;
			double y2 = coord[j].second;
			double dist = FindDistance(x1, y1, x2, y2);

			graph[i].push_back({ dist, j });
			graph[j].push_back({ dist, i });
		}
	}

	priority_queue <pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
	pq.push({ 0.0, 0 });

	double ans = 0;

	while (!pq.empty()) {
		double nowDist = pq.top().first;
		int nowNode = pq.top().second;
		pq.pop();

		if (check[nowNode] == true)
			continue;

		check[nowNode] = true;

		ans += nowDist;

		for (int i = 0; i < graph[nowNode].size(); i++) {
			double nextCost = graph[nowNode][i].first;
			int nextNode = graph[nowNode][i].second;

			if (check[nextNode] == false)
				pq.push({ nextCost, nextNode });
		}
	}
	cout << fixed;
	cout.precision(2);

	cout << ans << endl;
}