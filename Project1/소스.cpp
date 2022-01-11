#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

const int MAX = 101;
int N, M;
int arr[MAX][MAX];
int Y[4] = { 1, -1, 0, 0 };
int X[4] = { 0, 0, -1, 1 };


void Air() {
	queue<pii> q;
	q.push({ 1, 1 });
	arr[1][1] = 3;

	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = Y[i] + cy;
			int nx = X[i] + cx;

			if (ny >= 1 && ny <= N && nx >= 1 && nx <= M) {
				if (arr[ny][nx] == 0) {
					arr[ny][nx] = 3;
					q.push({ ny, nx });
				}
			}
		}
	}
}

void Melt() {
	map<pii, int> mp;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (arr[i][j] == 1) {
				for (int k = 0; k < 4; k++) {
					int ny = i + Y[k];
					int nx = j + X[k];

					if (arr[ny][nx] == 3) {
						mp[{i, j}]++;

						if (mp[{i, j}] == 2) {
							arr[i][j] = 4;
						}
					}
				}
			}
		}
	}
}

void Set() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (arr[i][j] == 3)
				arr[i][j] = 0;
			if (arr[i][j] == 4)
				arr[i][j] = 0;
		}
	}
}

int Count() {
	int count = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++)
			if (arr[i][j] == 1)
				count++;
	}

	return count;
}

bool Check() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (arr[i][j] == 1)
				return false;
		}
	}

	return true;
}

int main() {
	fastio;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++)
			cin >> arr[i][j];
	}
	int ans = 0;
	int count = 0;
	while (1) {
		bool flag = Check();

		if (flag == true)
			break;

		Air();
		Melt();
		Set();
		ans++;
	}

	cout << ans << endl;
}