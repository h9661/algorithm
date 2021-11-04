#include <bits/stdc++.h>
#pragma warning (disable : 4996)
#pragma warning (disable : 6385)
#pragma warning (disable : 6386)
#pragma warning (disable : 6200)
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

char arr[3072][6143];

void draw(int row, int col) {
	arr[row][col] = '*';

	arr[row + 1][col - 1] = '*';
	arr[row + 1][col + 1] = '*';

	for (int i = 0; i < 5; i++)
		arr[row + 2][col - 2 + i] = '*';
}

void dfs(int len, int row, int col) {
	if (len == 3) {
		draw(row, col);
		return;
	}

	dfs(len / 2, row, col);
	dfs(len / 2, row + len / 2, col - len / 2);
	dfs(len / 2, row + len / 2, col + len / 2);
}

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2 * N - 1; j++)
			arr[i][j] = ' ';
	}

	dfs(N, 0, N - 1);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2 * N - 1; j++)
			cout << arr[i][j];
		cout << endl;
	}

	return 0;
}