#include <bits/stdc++.h>
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
ll arr[MAX][MAX];

int main() {
	int N;
	cin >> N;

	int M;
	cin >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j)
				arr[i][j] = 0;
			else
				arr[i][j] = INF;
		}
	}

	for (int i = 0; i < M; i++) {
		int big, small;
		cin >> big >> small;

		arr[small][big] = 1;
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (arr[i][j] > arr[i][k] + arr[k][j])
					arr[i][j] = arr[i][k] + arr[k][j];
			}
		}
	}

	vector<int> ans(N + 1, 0);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i != j) {
				if (arr[i][j] != INF) {
					ans[j]++;
					ans[i]++;
				}
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << N - ans[i] - 1 << endl;
	}

	return 0;
}