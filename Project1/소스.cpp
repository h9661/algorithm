#include <bits/stdc++.h>
#define endl '\n'
#define ll pair<long long, long long>
#define ii pair<int, int>
using namespace std;

const int MAX = 50 + 1;
int graph[MAX][MAX];
bool check[MAX][MAX];
int N, M;
int r, c, d;
bool ansFlag = false;

int Y[4] = { -1,0,1,0 };
int X[4] = { 0,1,0,-1 };

bool isValidPos(int y, int x) {
	if (y >= 0 and y < N and x >= 0 and x < M)
		return true;
	else
		return false;
}

void dfs(int currentY, int currentX, int currentDir, int count) {
	if (ansFlag)
		return;

	for (int i = 0; i < 4; i++) {
		int nextDir = (currentDir + 3 - i) % 4;
		int nextY = currentY + Y[nextDir];
		int nextX = currentX + X[nextDir];

		if (!isValidPos(nextY, nextX) or graph[nextY][nextX] == 1)
			continue;

		if (check[nextY][nextX] == false and graph[nextY][nextX] == 0) {
			check[nextY][nextX] = true;
			dfs(nextY, nextX, nextDir, count + 1);
		}
	}

	int nextY = currentY;
	int nextX = currentX;

	if (currentDir == 0)
		nextY += 1;
	else if (currentDir == 1)
		nextX -= 1;
	else if (currentDir == 2)
		nextY -= 1;
	else
		nextX += 1;

	if (isValidPos(nextY, nextX)) {
		if (graph[nextY][nextX] == 0)
			dfs(nextY, nextX, currentDir, count);
		else {
			if (ansFlag == false) {
				cout << count << endl;
				ansFlag = true;
			}
		}
	}
}

int main() {
	cin >> N >> M;
	cin >> r >> c >> d;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cin >> graph[i][j];
	}

	check[r][c] = true;
	dfs(r, c, d, 1);
}