#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define ii pair<int, int>
using namespace std;

const int MAX = 500 + 1;
vector<ii> graph[MAX];
int dist[MAX][MAX];
const int INF = 1e9;
int N, M;
int Count[MAX];

int main() {
	cin >> N >> M;

	fill(&dist[0][0], &dist[MAX - 1][MAX], INF);


	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;

		dist[from][to] = 1;
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	for (int from = 1; from <= N; from++) {
		for (int to = 1; to <= N; to++)
			if (dist[from][to] == INF)
				continue;
			else {
				Count[to]++;	// ����Ŵ�� �޴� Ƚ��
				Count[from]++;	// ����Ŵ�� �ִ� Ƚ��
			}
	}

	int ans = 0;

	for (int i = 1; i <= N; i++) {
		if (Count[i] == N - 1)	// �޴� Ƚ�� + �ִ� Ƚ�� = N - 1�̸� ���� �˱� ����
			ans++;
	}

	cout << ans << endl;
}