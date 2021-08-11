#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define ii pair<int, int>
using namespace std;

// 백준 2623
// 위상 정렬

vector<vector<int>> graph;
vector<int> indiag;
vector<int> store;

int main() {
	int N, M;
	cin >> N >> M;

	graph.resize(N + 1);
	indiag.resize(N + 1);

	for (int i = 1; i <= M; i++) {
		int num;
		cin >> num;

		int* arr = new int[num];
		for (int j = 0; j < num; j++) {
			cin >> arr[j];
		}

		for (int j = 0; j < num - 1; j++) {
			int u = arr[j];
			int v = arr[j + 1];

			graph[u].push_back(v);
			indiag[v]++;
		}
	}

	queue<int> q;
	
	for (int i = 1; i <= N; i++) {
		if (indiag[i] == 0)
			q.push(i);
	}

	while (!q.empty()) {
		int currentNode = q.front();

		q.pop();

		if (indiag[currentNode] == 0)
			store.push_back(currentNode);

		for (int i = 0; i < graph[currentNode].size(); i++) {
			int nextNode = graph[currentNode][i];

			if (--indiag[nextNode] == 0)
				q.push(nextNode);
		}
	}

	bool check = false;

	for (int i = 1; i <= N; i++) {
		if (indiag[i] != 0)
			check = true;
	}

	if (check)
		cout << "0" << endl;
	else {
		for (auto i : store)
			cout << i << endl;
	}

	return 0;
}