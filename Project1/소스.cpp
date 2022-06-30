#include <bits/stdc++.h>
#define endl '\n'
#define ll pair<long long, long long>
#define ii pair<int, int>
using namespace std;

const int MAX = 100;
int graphNomal[MAX][MAX];
int graphNotNomal[MAX][MAX];
bool check[MAX][MAX];
int N;

int Y[4] = { -1, 1, 0, 0 };
int X[4] = { 0, 0, -1, 1 };

void bfs1(int row, int col, int color) {
	queue<ii> q;
	q.push({ row, col });
	check[row][col] = true;
	
	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cy + Y[i];
			int nx = cx + X[i];

			if (0 <= ny and ny < N and 0 <= nx and nx < N) {
				if (graphNomal[ny][nx] == color and check[ny][nx] == false) {
					check[ny][nx] = true;
					q.push({ ny,nx });
				}
			}
		}
	}
}
void bfs2(int row, int col, int color) {
	queue<ii> q;
	q.push({ row, col });
	check[row][col] = true;

	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cy + Y[i];
			int nx = cx + X[i];

			if (0 <= ny and ny < N and 0 <= nx and nx < N) {
				if (graphNotNomal[ny][nx] == color and check[ny][nx] == false) {
					check[ny][nx] = true;
					q.push({ ny,nx });
				}
			}
		}
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char color;
			cin >> color;

			if (color == 'R') {
				graphNomal[i][j] = 1;
				graphNotNomal[i][j] = 1;
			}
			else if (color == 'G') {
				graphNomal[i][j] = 2;
				graphNotNomal[i][j] = 1;
			}
			else {
				graphNomal[i][j] = 3;
				graphNotNomal[i][j] = 2;
			}
		}
	}

	int count1 = 0;
	int count2 = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (check[i][j] == false) {
				bfs1(i, j, graphNomal[i][j]);
				count1++;
			}
		}
	}
	memset(check, false, sizeof(check));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (check[i][j] == false) {
				bfs2(i, j, graphNotNomal[i][j]);
				count2++;
			}
		}
	}

	cout << count1 << " " << count2 << endl;
}