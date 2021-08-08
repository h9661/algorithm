#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define ii pair<int, int>
using namespace std;

// 백준 4963
// BFS 알고리즘

int w, h;
const int MAX = 51;
int graph[MAX][MAX];
bool check[MAX][MAX];
int Y[8] = { 1, -1, 0, 0 , 1, 1, -1, -1};
int X[8] = { 0, 0, 1, -1, 1, -1, 1, -1 };

void bfs(int i, int j) {
	queue<ii> q;
	q.push({ i, j });
	check[i][j] = true;

	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;

		q.pop();

		for (int i = 0; i < 8; i++) {
			int ny = Y[i] + cy;
			int nx = X[i] + cx;

			if (ny >= 1 && ny <= h && nx >= 1 && nx <= w && check[ny][nx] == false && graph[ny][nx] == 1) {
				q.push({ ny, nx });
				check[ny][nx] = true;
			}
		}
	}
}

int main() {
	while (1) {
		cin >> w >> h;

		if (w == 0 && h == 0)
			break;

		fill(&graph[0][0], &graph[MAX - 1][MAX], 0);
		fill(&check[0][0], &check[MAX - 1][MAX], 0);

		for (int i = 1; i <= h; i++)
			for (int j = 1; j <= w; j++)
				cin >> graph[i][j];

		int ans = 0;

		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				if (check[i][j] == false && graph[i][j] == 1) {
					bfs(i, j);
					ans++;
				}
			}
		}

		cout << ans << endl;
	}
}