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

const int MAX = 100;
int matrix1[MAX][MAX];
int matrix2[MAX][MAX];
int ans[MAX][MAX];

int main() {
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cin >> matrix1[i][j];
	}

	int K;
	cin >> M >> K;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < K; j++)
			cin >> matrix2[i][j];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			for (int k = 0; k < M; k++)
				ans[i][j] += matrix1[i][k] * matrix2[k][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++)
			cout << ans[i][j] << " ";
		cout << endl;
	}

	return 0;
}