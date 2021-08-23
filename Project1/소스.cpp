#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

const int MAX = 2000 + 1;
const int INF = 2e9;
vector<pii> graph[MAX];
vector<int> destinationArr;
vector<int> ans;
int distS[MAX];

void djk(int start, int dist[]) {
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	dist[start] = 0;
	pq.push({ 0, start });

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
		for (int i = 0; i < MAX; i++) {
			graph[i].clear();
		}
		destinationArr.clear();
		ans.clear();

		int V, E, T;
		cin >> V >> E >> T;

		int S, G, H;
		cin >> S >> G >> H;

		for (int i = 0; i < E; i++) {
			int from, to, val;
			cin >> from >> to >> val;

			if (from == G && to == H || from == H && to == G) {
				graph[from].push_back({ val * 2 - 1, to });
				graph[to].push_back({ val * 2 - 1, from });
			}
			else {
				graph[from].push_back({ val * 2, to });
				graph[to].push_back({ val * 2, from });
			}
		}

		for (int i = 0; i < T; i++) {
			int des;
			cin >> des;

			destinationArr.push_back(des);
		}

		fill(distS, distS + MAX, INF);
		djk(S, distS);

		for (int i = 0; i < destinationArr.size(); i++) {
			if (distS[destinationArr[i]] % 2 == 1)
				ans.push_back(destinationArr[i]);
		}

		sort(ans.begin(), ans.end());

		for (auto i : ans)
			cout << i << " ";
		cout << endl;
	}
}