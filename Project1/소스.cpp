#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int Y[4] = { 1, -1, 0, 0 };
int X[4] = { 0, 0, -1, 1 };

void bfs(int i, int j, vector<vector<int>>& arr, int M, int N) {
	queue<pair<int, int>> q;
	q.push({ i, j });
	arr[i][j] = 0;

	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int ny = cy + Y[k];
			int nx = cx + X[k];

			if (ny >= 0 && ny < M && nx >= 0 && nx < N) {
				if (arr[ny][nx] != 0) {
					q.push({ ny, nx });
					arr[ny][nx] = 0;
				}
			}
		}
	}
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int M, N, K;
		cin >> M >> N >> K;

		vector<vector<int>> arr(M, vector<int>(N, 0));

		for (int i = 0; i < K; i++) {
			int y, x;
			cin >> y >> x;
			arr[y][x] = 1;
		}

		int answer = 0;

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (arr[i][j] == 1) {
					bfs(i, j, arr, M, N);
					answer++;
				}
			}
		}

		cout << answer << endl;
	}
}