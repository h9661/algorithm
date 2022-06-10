#include <bits/stdc++.h>
#define endl '\n'
#define ii pair<long long, long long>
using namespace std;

const int MAX = 101;
vector<int> graph[MAX];
bool check[MAX];

int bfs() {
	queue<int> q;
	q.push(1);
	check[1] = true;
	int count = 0;

	while (!q.empty()) {
		int curNode = q.front();
		q.pop();

		for (int i = 0; i < graph[curNode].size(); i++) {
			int nxtNode = graph[curNode][i];

			if (check[nxtNode] == false) {
				q.push(nxtNode);
				check[nxtNode] = true;
				count++;
			}
		}
	}

	return count;
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N;
	cin >> N;

	int M;
	cin >> M;

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	cout << bfs() << endl;
}