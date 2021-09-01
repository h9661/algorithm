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
vector<int> graph[MAX];
int indeg[MAX];
int order[MAX];
int orderCount[MAX];

int main() {
	int tt;
	cin >> tt;
	
	int k = 1;

	while (tt--) {
		int K, M, P;
		cin >> K >> M >> P;

		for (int i = 0; i < MAX; i++)
			graph[i].clear();

		fill(indeg, indeg + MAX, 0);
		fill(order, order + MAX, 0);
		fill(orderCount, orderCount + MAX, 0);

		for (int i = 0; i < P; i++) {
			int u, v;
			cin >> u >> v;

			graph[u].push_back(v);
			indeg[v]++;
		}
		
		queue<int> q;
		for (int i = 1; i <= M; i++) {
			if (indeg[i] == 0) {
				q.push(i);
				order[i] = 1;
			}
		}

		while (!q.empty()) {
			int now = q.front();
			q.pop();

			for (int i = 0; i < graph[now].size(); i++) {
				int next = graph[now][i];

				// 순서가 크면 바꿔주고 카운트 1
				if (order[now] > order[next]) {
					order[next] = order[now];
					orderCount[next] = 1;
				}
				else if (order[now] == order[next])
					orderCount[next]++;

				if (--indeg[next] == 0) {
					if (orderCount[next] >= 2)
						order[next] = order[next] + 1;

					q.push(next);
				}
			}
		}
		
		cout << K << " " << *max_element(order, order + M + 1) << endl;
	}
}