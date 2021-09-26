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

const int MAX = 200 + 1;
vector<int> graph[MAX];
bool capacity[MAX];
int parent[MAX];
int N, M;

bool dfs(int x) {
	for (int i = 0; i < graph[x].size(); i++) {
		int y = graph[x][i];

		if (capacity[y])
			continue;
		capacity[y] = true;

		if (parent[y] == 0 || dfs(parent[y])) {
			parent[y] = x;
			return true;
		}
	}

	return false;
}

int main() {
	cin >> N >> M;

	const int ROOM = 100;

	for (int i = 0; i < M; i++) {
		int person, notebook;
		cin >> person >> notebook;

		graph[person].push_back(notebook + ROOM);
	}

	int count = 0;

	for (int i = 1; i <= N; i++) {
		fill(capacity, capacity + MAX, false);

		if (dfs(i))
			count++;
	}

	cout << count << endl;
}