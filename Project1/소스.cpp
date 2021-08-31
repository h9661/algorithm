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
vector<vector<pll>> graph;
vector<int> indeg;
int N, M;
int countArr[MAX][MAX];

int main() {
	cin >> N >> M;

	indeg.resize(N + 1);
	graph.resize(N + 1);

	for (int i = 0; i < M; i++) {
		int X, Y, K;;
		cin >> X >> Y >> K;

		graph[Y].push_back({ X, K });
		indeg[X]++;
	}

	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (indeg[i] == 0) {
			q.push(i);
			countArr[i][i] = 1;
		}
	}

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i].first;
			int num = graph[now][i].second;

			for (int j = 1; j <= N; j++)
				countArr[next][j] += countArr[now][j] * num;
			
			if (--indeg[next] == 0)
				q.push(next);
		}
	}


	for (int i = 1; i <= N; i++) {
		if (countArr[N][i] != 0)
			cout << i << " " << countArr[N][i] << endl;
	}

	return 0;
}