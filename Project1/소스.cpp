#include <bits/stdc++.h>
#pragma warning (disable : 4996)
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

const int MAX = 100 + 1;
const int INF = 2e9;
int graph[MAX][MAX];
int costMap[MAX][MAX];
int Y[4] = { -1, 1, 0, 0 };
int X[4] = { 0, 0, 1, -1 };
bool check[MAX][MAX];
int N, M;

void bfs() {
	priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> q;
	q.push({ 0, {0, 0} });
	costMap[0][0] = 0;
	check[0][0] = true;

	while (!q.empty()) {
		int currentY = q.top().second.first;
		int currentX = q.top().second.second;
		int currentCost = q.top().first;
		q.pop();

		if (currentY == M - 1 && currentX == N - 1)
			return;

		for (int i = 0; i < 4; i++) {
			int nextY = currentY + Y[i];
			int nextX = currentX + X[i];

			if (nextY >= 0 && nextY < M && nextX >= 0 && nextX < N && check[nextY][nextX] == false) {
				if (costMap[nextY][nextX] > currentCost) {
					if (graph[nextY][nextX] == 0) {
						costMap[nextY][nextX] = currentCost;
						q.push({ currentCost,{nextY, nextX} });
					}
					else {
						costMap[nextY][nextX] = currentCost + 1;
						q.push({ currentCost + 1,{nextY, nextX} });
					}
				}

				check[nextY][nextX] = true;
			}
		}
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			char temp;
			cin >> temp;

			if (temp == '0')
				graph[i][j] = 0;
			else
				graph[i][j] = 1;
		}
	}

	fill(&costMap[0][0], &costMap[MAX - 1][MAX], INF);

	bfs();

	cout << costMap[M - 1][N - 1] << endl;

	return 0;
}