#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

const int MAX = 500 + 1;

int relation[MAX][MAX];
int arr[MAX];
int indeg[MAX];
vector<int> graph[MAX];
bool printCheck[MAX];
vector<int> store;

int main() {
	fastio;
	int tt;
	cin >> tt;

	while (tt--) {
		fill(&relation[0][0], &relation[MAX - 1][MAX], 0);
		fill(arr, arr + MAX, 0);
		fill(indeg, indeg + MAX, 0);
		fill(printCheck, printCheck + MAX, false);
		for (int i = 0; i < MAX; i++)
			graph[i].clear();
		store.clear();


		int n;
		cin >> n;

		for (int i = 1; i <= n; i++)
			cin >> arr[i];

		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				int u = arr[i];
				int v = arr[j];

				relation[u][v] = 1;
			}
		}

		int m;
		cin >> m;

		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;

			if (relation[u][v] == 1) {
				relation[u][v] = 0;
				relation[v][u] = 1;
			}
			else if (relation[v][u] = 1) {
				relation[v][u] = 0;
				relation[u][v] = 1;
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (relation[i][j] == 1) {
					graph[i].push_back(j);
					indeg[j]++;
				}
			}
		}

		queue<int> q;

		for (int i = 1; i <= n; i++) {
			if (indeg[i] == 0)
				q.push(i);
		}

		while (!q.empty()) {
			int currentNode = q.front();
			q.pop();

			if (printCheck[currentNode] == false) {
				store.push_back(currentNode);
				printCheck[currentNode] = true;
			}

			for (int i = 0; i < graph[currentNode].size(); i++) {
				int nextNode = graph[currentNode][i];

				if (--indeg[nextNode] == 0)
					q.push(nextNode);
			}
		}

		bool check = true;
		for (int i = 1; i <= n; i++) {
			if (printCheck[i] == false)
				check = false;
		}

		if (check) {
			for (auto i : store)
				cout << i << " ";
		}
		else {
			cout << "IMPOSSIBLE";
		}
		cout << endl;
	}
}