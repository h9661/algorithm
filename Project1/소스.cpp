#include <bits/stdc++.h>
#pragma warning (disable : 4996)
#pragma warning (disable : 6385)
#pragma warning (disable : 6386)
#pragma warning (disable : 6200)
#pragma warning (disable : 26812)
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

const int MAX = 100;
int graph[MAX][MAX];
int Y[4] = { -1, 1, 0, 0 };
int X[4] = { 0, 0, -1, 1 };
int N, M, K;
int ans = 0;
vector<int> area;

void bfs(int y, int x) {
	int count = 0;
	queue<pii> q;
	q.push({ y, x });
	graph[y][x] = 1;
	count++;

	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cy + Y[i];
			int nx = cx + X[i];

			if (ny < M && ny >= 0 && nx < N && nx >= 0) {
				if (graph[ny][nx] == 0) {
					q.push({ ny, nx });
					graph[ny][nx] = 1;
					count++;
				}
			}
		}
	}

	area.push_back(count);
}

int main() {
	fastio;


	cin >> N >> M >> K;

	for (int i = 0; i < K; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		for (int y = x1; y < x2; y++) {
			for (int x = y1; x < y2; x++) {
				graph[y][x] = 1;
			}
		}
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (graph[i][j] == 0) {
				bfs(i, j);
				ans++;
			}
		}
	}
	sort(area.begin(), area.end());
	cout << ans << endl;
	for (auto i : area)
		cout << i << " ";
	return 0;
}