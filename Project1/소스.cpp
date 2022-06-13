#include <bits/stdc++.h>
#define endl '\n'
#define ll pair<long long, long long>
#define ii pair<int, int>
using namespace std;

const int MAX = 1000;
int Y[4] = { -1, 1, 0, 0 };
int X[4] = { 0,0, -1, 1 };
int graph[MAX][MAX];
bool check[MAX][MAX];
int N, M;

int bfs() {
	queue<pair<ii, int>> q;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (graph[i][j] == 1) {
				q.push({{i, j}, 0});
				check[i][j] = true;
			}
		}
	}

	int retval = 0;

	while (!q.empty()) {
		int curY = q.front().first.first;
		int curX = q.front().first.second;
		int curC = q.front().second;
		q.pop();
		retval = max(retval, curC);

		for (int i = 0; i < 4; i++) {
			int nxtY = curY + Y[i];
			int nxtX = curX + X[i];
			int nxtC = curC + 1;

			if (nxtY >= 0 && nxtY < N && nxtX >= 0 && nxtX < M) {
				if (check[nxtY][nxtX] == false && graph[nxtY][nxtX] == 0) {
					q.push({ {nxtY, nxtX}, nxtC });
					graph[nxtY][nxtX] = 1;
					check[nxtY][nxtX] = true;
				}
			}
		}
	}

	return retval;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> M >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cin >> graph[i][j];
	}

	int ans = bfs();
	int flag = false;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (graph[i][j] == 0)
				flag = true;
		}
	}


	if (flag)
		cout << -1 << endl;
	else
		cout << ans << endl;
}