#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define ii pair<int, int>
using namespace std;

// 백준 4485
// 2차원 배열을 이용한 다익스트라 알고리즘

int N;
const int MAX = 125 + 1;
const int INF = 50000;
int graph[MAX][MAX];
int check[MAX][MAX];
int Y[4] = { 1, -1, 0, 0 };
int X[4] = { 0, 0, -1, 1 };

void bfs() {
	queue<ii> q;
	q.push({ 1, 1 });
	check[1][1] = graph[1][1];

	while (!q.empty()) {
		int currentY = q.front().first;
		int currentX = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextY = Y[i] + currentY;
			int nextX = X[i] + currentX;

			if (nextY >= 1 && nextY <= N && nextX >= 1 && nextX <= N) {
				if (check[nextY][nextX] > check[currentY][currentX] + graph[nextY][nextX]) {
					check[nextY][nextX] = check[currentY][currentX] + graph[nextY][nextX];
					q.push({ nextY, nextX });
				}
			}
		}
	}
}

int main() {
	int count = 1;
	while (1) {
		memset(graph, 0, sizeof(graph));
		memset(check, INF, sizeof(check));
		
		cin >> N;

		if (N == 0)
			break;

		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				cin >> graph[i][j];

		bfs();

		cout << "Problem " << count << ": ";
		count++;
		cout << check[N][N] << endl;
	}
}