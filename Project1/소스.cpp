#include <bits/stdc++.h>
#define endl '\n'
#define ii pair<long long, long long>
using namespace std;

const int MAX = 100;
int graph[MAX][MAX];
bool check[MAX][MAX];
int Y[4] = { -1, 1, 0,0 };
int X[4] = { 0, 0, -1, 1 };

int bfs(int N, int M) {
	queue<pair<ii, int>> q;
	q.push({ {0, 0}, 1 });
	check[0][0] = true;

	while (!q.empty()) {
		int curY = q.front().first.first;
		int curX = q.front().first.second;
		int curC = q.front().second;
		q.pop();

		if (curY == N - 1 and curX == M - 1)
			return curC;

		for (int i = 0; i < 4; i++) {
			int nxtY = curY + Y[i];
			int nxtX = curX + X[i];
			int nxtC = curC + 1;

			if (nxtY >= 0 && nxtY < N && nxtX >= 0 && nxtX < M) {
				if (check[nxtY][nxtX] == false && graph[nxtY][nxtX] == 1) {
					q.push({ {nxtY, nxtX}, nxtC });
					check[nxtY][nxtX] = true;
				}
			}
		}
	}
}

int main() {
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char x;
			cin >> x;

			graph[i][j] = x - 48;
		}
	}

	cout << bfs(N, M) << endl;
}