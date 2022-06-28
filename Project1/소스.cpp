#include <bits/stdc++.h>
#define endl '\n'
#define ll pair<long long, long long>
#define ii pair<int, int>
using namespace std;

int Y[4] = { 1 ,0, -1, 0 };
int X[4] = { 0, 1, 0, -1 };
int N, M;
const int MAX = 500;
int graph[MAX][MAX];
int ans = 0;

void dfs(int y, int x, int count, int sum, vector<vector<bool>>& check) {
	if (count == 3) {
		ans = max(ans, sum);
	}
	else {
		for (int i = 0; i < 4; i++) {
			int ny = y + Y[i];
			int nx = x + X[i];

			if (0 <= ny and ny < N and 0 <= nx and nx < M) {
				if (check[ny][nx] == false) {
					check[ny][nx] = true;
					dfs(ny, nx, count + 1, sum + graph[ny][nx], check);
					check[ny][nx] = false;
				}
			}
		}
	}
}

void ex(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int count = 0;
		int sum = graph[y][x];

		int ny = Y[(i) % 4] + y;
		int nx = X[(i) % 4] + x;

		if (ny >= 0 and ny < N and nx >= 0 and nx < M) {
			sum += graph[ny][nx];
			count++;
		}

		ny = Y[(i + 1) % 4] + y;
		nx = X[(i + 1) % 4] + x;

		if (ny >= 0 and ny < N and nx >= 0 and nx < M) {
			sum += graph[ny][nx];
			count++;
		}

		ny = Y[(i + 2) % 4] + y;
		nx = X[(i + 2) % 4] + x;

		if (ny >= 0 and ny < N and nx >= 0 and nx < M) {
			sum += graph[ny][nx];
			count++;
		}

		if(count == 3)
			ans = max(ans, sum);
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> graph[i][j];

	vector<vector<bool>> check(N, vector<bool>(M, false));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (check[i][j] == false) {
				check[i][j] = true;
				dfs(i, j, 0, graph[i][j], check);
				check[i][j] = false;
			}

			ex(i, j);
		}
	}

	cout << ans << endl;
}