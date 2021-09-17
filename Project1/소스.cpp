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

const int MAX = 400 + 1;
vector<int> graph[MAX];
int d[MAX];
bool c[MAX];

bool dfs(int x) {
	for (int i = 0; i < graph[x].size(); i++) {
		int t = graph[x][i];

		if (c[t])
			continue;

		c[t] = true;

		if (d[t] == 0 || dfs(d[t])) {
			d[t] = x;
			return true;
		}
	}

	return false;
}

int main() {
	int N, M;
	cin >> N >> M;

	const int ROOM = 200;

	for (int i = 1; i <= N; i++) {
		int k;
		cin >> k;

		while (k--) {
			int temp;
			cin >> temp;

			graph[i].push_back(temp + ROOM);
		}
	}

	int count = 0;

	for (int i = 1; i <= N; i++) {
		fill(c, c + MAX, false);
		if (dfs(i))
			count++;
	}

	cout << count << endl;
}