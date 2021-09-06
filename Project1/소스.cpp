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
vector<pii> graph[MAX];
bool check[MAX];

int arr[MAX][MAX];

int main() {
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			cin >> arr[i][j];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			if (i == j)
				continue;

			graph[i].push_back({ arr[i][j], j });
			graph[j].push_back({ arr[i][j], i });
		}
	}

	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({ 0, 1 });

	ll ans = 0;

	while (!pq.empty()) {
		int currentCost = pq.top().first;
		int currentNode = pq.top().second;
		pq.pop();

		if (check[currentNode] == true)
			continue;

		check[currentNode] = true;
		ans += currentCost;

		for (int i = 0; i < graph[currentNode].size(); i++) {
			int nextCost = graph[currentNode][i].first;
			int nextNode = graph[currentNode][i].second;

			if (check[nextNode] == false)
				pq.push({ nextCost, nextNode });
		}
	}

	cout << ans << endl;
}