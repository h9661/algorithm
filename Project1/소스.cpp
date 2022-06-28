#include <bits/stdc++.h>
#define endl '\n'
#define ll pair<long long, long long>
#define ii pair<int, int>
using namespace std;

int M, N, H;

const int MAX = 100;
int graph[MAX][MAX][MAX];
bool check[MAX][MAX][MAX];
int Z[6] = { 0, 0, 0, 0, -1, 1 };
int Y[6] = { -1, 1, 0, 0 , 0, 0};
int X[6] = { 0, 0, -1, 1 , 0, 0};

int bfs() {
	queue<tuple<int, int, int, int>> q;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (graph[i][j][k] == 1) {
					q.push(make_tuple(i, j, k, 0));
					check[i][j][k] = true;
				}
			}
		}
	}
	int retval = 0;

	while (!q.empty()) {
		int ch = get<0>(q.front());
		int cy = get<1>(q.front());
		int cx = get<2>(q.front());
		int cc = get<3>(q.front());
		retval = max(retval, cc);

		q.pop();

		for (int i = 0; i < 6; i++) {
			int nh = ch + Z[i];
			int ny = cy + Y[i];
			int nx = cx + X[i];
			int nc = cc + 1;

			if (nh >= 0 and nh < H and ny >= 0 and ny < N and nx >= 0 and nx < M) {
				if (graph[nh][ny][nx] == 0 and check[nh][ny][nx] == false) {
					graph[nh][ny][nx] = 1;
					check[nh][ny][nx] = true;
					q.push(make_tuple(nh, ny, nx, nc));
				}
			}
		}
	}

	return retval;
}

int main() {
	cin >> M >> N >> H;

	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++)
				cin >> graph[k][i][j];
		}
	}

	bool flag = true;
	int retval = bfs();

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (graph[i][j][k] == 0)
					flag = false;
			}
		}
	}

	if (flag)
		cout << retval << endl;
	else
		cout << -1 << endl;
}