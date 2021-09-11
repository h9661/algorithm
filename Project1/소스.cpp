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
bool check[MAX];
vector<int> graph[MAX];
int start, des;

int bfs(int start, int des) {
	queue<pii> q;
	q.push({ 0, start });
	check[start] = true;

	while (!q.empty()) {
		int ct = q.front().first;
		int cn = q.front().second;
		q.pop();

		if (cn == des)
			return ct;

		for (int i = 0; i < graph[cn].size(); i++) {
			int nt = ct + 1;
			int nn = graph[cn][i];

			if (check[nn] == false) {
				q.push({ nt, nn });
				check[nn] = true;
			}
		}
	}

	return -1;
}

int main(){
	int n;
	cin >> n;

	cin >> start >> des;

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	cout << bfs(start, des) << endl;
}