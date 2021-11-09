#include <bits/stdc++.h>
#pragma warning (disable : 4996)
#pragma warning (disable : 6385)
#pragma warning (disable : 6386)
#pragma warning (disable : 6200)
#pragma warning (disable : 26812)
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

const int MAX = 16 + 1;
int arr[MAX][MAX];
int N;
int ans = 0;

typedef enum Type {
	TYPE1 = 0,
	TYPE2 = 1,
	TYPE3 = 2
}PIPE_TYPE;

void dfs(pii start, pii end, PIPE_TYPE type) {
	if (end.first == N && end.second == N) {
		if (type == TYPE2) {
			for (int i = start.first; i <= end.first; i++) {
				for (int j = start.second; j <= end.second; j++) {
					if (arr[i][j] == 1)
						return;
				}
			}
		}
		else if (type == TYPE1) {
			if (arr[start.first][start.second] == 1 || arr[end.first][end.second] == 1)
				return;
		}
		else {
			if (arr[start.first][start.second] == 1 || arr[end.first][end.second] == 1)
				return;
		}

		ans++;
		return;
	}

	if (type == TYPE1) {
		if (end.first > N || end.second > N)
			return;

		if (arr[start.first][start.second] == 1 || arr[end.first][end.second] == 1)
			return;
		else {
			dfs({ start.first, start.second + 1 }, { end.first, end.second + 1 }, TYPE1);
			dfs({ start.first, start.second + 1 }, { end.first + 1, end.second + 1 }, TYPE2);
		}
	}

	if (type == TYPE2) {
		if (end.first > N || end.second > N)
			return;

		for (int i = start.first; i <= end.first; i++) {
			for (int j = start.second; j <= end.second; j++) {
				if (arr[i][j] == 1)
					return;
			}
		}

		dfs({ start.first + 1, start.second + 1 }, { end.first, end.second + 1 }, TYPE1);
		dfs({ start.first + 1, start.second + 1 }, { end.first + 1, end.second + 1 }, TYPE2);
		dfs({ start.first + 1, start.second + 1 }, { end.first + 1, end.second }, TYPE3);
	}

	if (type == TYPE3) {
		if (end.first > N || end.second > N)
			return;

		if (arr[start.first][start.second] == 1 || arr[end.first][end.second] == 1)
			return;
		else {
			dfs({start.first + 1, start.second}, {end.first + 1, end.second + 1}, TYPE2);
			dfs({ start.first + 1, start.second }, { end.first + 1, end.second }, TYPE3);
		}
	}
}

int main() {
	fastio;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			cin >> arr[i][j];
	}

	dfs({ 1, 1 }, { 1, 2 }, TYPE1);

	cout << ans << endl;
}