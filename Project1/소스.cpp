#include <bits/stdc++.h>
#define endl '\n'
#define ll pair<long long, long long>
#define ii pair<int, int>
using namespace std;

int M, N;
const int MAX = 1010;
char graph[MAX][MAX];
vector<int> resArr;
bool visited[2][MAX][MAX];
int Y[4] = { -1, 1, 0, 0 };
int X[4] = { 0, 0, -1, 1 };

void bfs() {
	queue<pair<ii, ii>> q;
	q.push({ {0, 0}, {0, false} });
	visited[0][0][0] = true;

	while (!q.empty()) {
		int cy = q.front().first.first;
		int cx = q.front().first.second;
		int cc = q.front().second.first;
		int cb = q.front().second.second;
		q.pop();

		if (cy == M - 1 and cx == N - 1)
			resArr.push_back(cc + 1);

		for (int i = 0; i < 4; i++) {
			int ny = cy + Y[i];
			int nx = cx + X[i];
			int nc = cc + 1;
			int world = cb == false ? 0 : 1;

			if (ny >= 0 and ny < M and nx >= 0 and nx < N) {
				if (visited[world][ny][nx] == false) {
					if (graph[ny][nx] == '1') {
						if (cb == false) {
							q.push({ {ny, nx}, {nc, true} });
						}
					}

					if (graph[ny][nx] == '0') {
						q.push({ {ny, nx}, {nc, cb} });
						visited[world][ny][nx] = true;
					}
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			char x;
			cin >> x;

			graph[i][j] = x;
		}
	}

	bfs();

	if (resArr.size() == 0)
		cout << -1 << endl;
	else
		cout << *min_element(resArr.begin(), resArr.end()) << endl;
	
}