#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

int N, M;
const int MAX = 8 + 1;
int arr[MAX][MAX];
bool check[MAX][MAX];
int Y[4] = { -1, 1, 0, 0 };
int X[4] = { 0, 0, -1, 1 };
vector<int> store;

void bfs() {
	int graph[MAX][MAX];
	fill(&graph[0][0], &graph[MAX - 1][MAX], 0);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			graph[i][j] = arr[i][j];
	}

	queue<pii> q;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (graph[i][j] == 2) {
				q.push({ i, j });
				check[i][j] = true;
			}
		}
	}

	while (!q.empty()) {
		int currentY = q.front().first;
		int currentX = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextY = Y[i] + currentY;
			int nextX = X[i] + currentX;

			if (nextY >= 0 && nextY < N && nextX >= 0 && nextX < M) {
				if (check[nextY][nextX] == false && graph[nextY][nextX] != 1) {
					check[nextY][nextX] = true;
					graph[nextY][nextX] = 2;
					q.push({ nextY, nextX });
				}
			}
		}
	}

	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (graph[i][j] == 0)
				count++;
		}
	}

	store.push_back(count);
}

int main() {
	fastio;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];
	}

	for (int a = 0; a < N * M; a++) {
		if (arr[a / M][a % M] != 0)
			continue;

		for (int b = a + 1; b < N * M; b++) {
			if (arr[b / M][b % M] != 0)
				continue;

			for (int c = b + 1; c < N * M; c++) {
				if (arr[c / M][c % M] != 0)
					continue;

				fill(&check[0][0], &check[MAX - 1][MAX], false);

				arr[a / M][a % M] = 1;
				arr[b / M][b % M] = 1;
				arr[c / M][c % M] = 1;

				bfs();

				arr[a / M][a % M] = 0;
				arr[b / M][b % M] = 0;
				arr[c / M][c % M] = 0;
			}
		}
	}

	cout << *max_element(store.begin(), store.end()) << endl;
	
	return 0;
}