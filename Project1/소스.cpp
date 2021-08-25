#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

int board[10][10];
int row[10][10], col[10][10], matrix[10][10];

void dfs(int pos) {
	if (pos == 81) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++)
				cout<< board[i][j] << " ";
			cout << endl;
		}
		exit(0);
	}

	int y = pos / 9, x = pos % 9;

	if (board[y][x] == 0) {
		for (int i = 1; i <= 9; ++i) {
			if (!row[y][i] && !col[x][i] && !matrix[(y / 3) * 3 + x / 3][i]) {
				row[y][i] = col[x][i] = matrix[(y / 3) * 3 + x / 3][i] = true;
				board[y][x] = i;
				dfs(pos + 1);
				row[y][i] = col[x][i] = matrix[(y / 3) * 3 + x / 3][i] = false;
				board[y][x] = 0;
			}
		}
	}
	else
		dfs(pos + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			cin >> board[i][j];
	}

	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j)
			if (board[i][j] != 0) {
				row[i][board[i][j]] = col[j][board[i][j]] = matrix[(i / 3) * 3 + j / 3][board[i][j]] = true;
			}
	}
	dfs(0);
	return 0;
}