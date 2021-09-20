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

const int MAX = 2000 + 1;
vector<int> graph[MAX];
bool capacity[MAX];
int d[MAX];
int N, M;

bool dfs(int x) {
	for (int i = 0; i < graph[x].size(); i++) {
		int y = graph[x][i];

		if (capacity[y])
			continue;

		capacity[y] = true;

		if (d[y] == 0 || dfs(d[y])) {
			d[y] = x;
			return true;
		}
	}

	return false;
}

int main() {
	cin >> N >> M;

	const int ROOM = 1000;

	for (int i = 1; i <= N; i++) {
		int n;
		cin >> n;

		while (n--) {
			int temp;
			cin >> temp;

			graph[i].push_back(temp + ROOM);
		}
	}

	int count = 0;
	for (int i = 1; i <= N; i++) {
		fill(capacity, capacity + MAX, false);

		if (dfs(i)) {
			count++;
		}
	}

	cout << count << endl;

	return 0;
}