#include <bits/stdc++.h>
#define endl '\n'
#define ll pair<long long, long long>
#define ii pair<int, int>
using namespace std;

const int MAX = 25;
int graph[MAX][MAX];
bool check[MAX][MAX];
int Y[4] = { -1 , 1, 0, 0 };
int X[4] = { 0, 0, 1, -1 };

int dfs(int row, int col, int N) {
	queue<ii> q;
	q.push({ row, col });
	check[row][col] = true;
	int count = 1;

	while (!q.empty()) {
		int curY = q.front().first;
		int curX = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nxtY = curY + Y[i];
			int nxtX = curX + X[i];

			if (nxtY >= 0 && nxtY < N && nxtX >= 0 && nxtX < N) {
				if (graph[nxtY][nxtX] != 0 && check[nxtY][nxtX] == false) {
					q.push({ nxtY, nxtX });
					check[nxtY][nxtX] = true;
					count++;
				}
			}
		}
	}

	return count;
}

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char x;
			cin >> x;

			graph[i][j] = x - 48;
		}
	}

	vector<int> ansArr;
	int count = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (graph[i][j] != 0 && check[i][j] == false) {
				int c = dfs(i, j, N);
				ansArr.push_back(c);
				count++;
			}
		}
	}

	sort(ansArr.begin(), ansArr.end());
	cout << count << endl;
	for (auto i : ansArr)
		cout << i << endl;
}