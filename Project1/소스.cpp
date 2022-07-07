#include <bits/stdc++.h>
#define endl '\n'
#define ll pair<long long, long long>
#define ii pair<int, int>
using namespace std;

const int MAX = 100001;
vector<int> tree[MAX];
vector<bool> check(MAX, false);
map<int, int> parent;

void bfs() {
	queue<int> q;
	q.push(1);
	check[1] = true;

	while (!q.empty()) {
		int curC = q.front();
		q.pop();

		for (int i = 0; i < tree[curC].size(); i++) {
			int nxtC = tree[curC][i];

			if (check[nxtC] == false) {
				parent[nxtC] = curC;
				check[nxtC] = true;
				q.push(nxtC);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		int u, v;
		cin >> u >> v;

		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	bfs();

	for (int i = 2; i <= N; i++)
		cout << parent[i] << endl;
}