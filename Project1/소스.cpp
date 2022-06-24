#include <bits/stdc++.h>
#define endl '\n'
#define ll pair<long long, long long>
#define ii pair<int, int>
using namespace std;

const int MAX = 101;
const int INF = 1e9;
int graph[MAX][MAX];

int main() {
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int x;
			cin >> x;
			if (x != 0)
				graph[i][j] = x;
			else
				graph[i][j] = INF;
		}
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (graph[i][j] > graph[i][k] + graph[k][j])
					graph[i][j] = 1;
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (graph[i][j] == INF)
				graph[i][j] = 0;
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}
}