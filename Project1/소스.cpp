#include <bits/stdc++.h>
#pragma warning (disable : 4996)
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

int N, M, K1, K2;
const int MAX = 600 + 1;
vector<int> graph[MAX];
bool c[MAX];
int d[MAX];

bool dfs(int x) {
	for (int i = 0; i < graph[x].size(); i++) {
		int y = graph[x][i];

		if (c[y])
			continue;
		c[y] = true;

		if (d[y] == 0 || dfs(d[y])) {
			d[y] = x;
			return true;
		}
	}

	return false;
}

int main() {
	cin >> N >> M >> K1 >> K2;

	int count1 = 0;
	int count2 = 0;

	const int ROOM = 300;

	for (int i = 0; i < K1; i++) {
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v + ROOM);
	}

	for (int i = 1; i <= N; i++) {
		fill(c, c + MAX, false);

		if (dfs(i))
			count1++;
	}

	for (int i = 0; i < MAX; i++)
		graph[i].clear();
	fill(c, c + MAX, false);
	fill(d, d + MAX, 0);

	for (int i = 0; i < K2; i++) {
		int u, v;
		cin >> u >> v;
		
		graph[u].push_back(v + ROOM);
	}

	for (int i = 1; i <= N; i++) {
		fill(c, c + MAX, false);

		if (dfs(i))
			count2++;
	}

	if (count1 >= count2)
		cout << "그만 알아보자" << endl;
	else
		cout << "네 다음 힐딱이" << endl;

	return 0;
}