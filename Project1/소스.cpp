#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define ii pair<int, int>
using namespace std;

const int MAX = 100 + 1;
const int INF = 2e9;
vector<ii> graph[MAX];
vector<int> money;
vector<ll> income;
bool check[MAX];
int N, start, des, M;

bool bfs(int startNode, int targetNode) {
	queue<int> q;
	q.push(startNode);
	check[startNode] = true;

	while (!q.empty()) {
		int currentNode = q.front();
		q.pop();

		if (currentNode == targetNode)
			return true;

		for (int i = 0; i < graph[currentNode].size(); i++) {
			int nextNode = graph[currentNode][i].first;

			if (check[nextNode] == false) {
				check[nextNode] = true;
				q.push(nextNode);
			}
		}
	}
	
	return false;
}

int main() {
	cin >> N >> start >> des >> M;
	
	money.resize(N);
	income.resize(N);

	for (int i = 0; i < M; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;

		graph[from].push_back({ to, -cost });
	}

	for (int i = 0; i < N; i++)
		cin >> money[i];

	ll temp1[MAX];
	ll temp2[MAX];

	fill(income.begin(), income.end(), -INF);
	fill(temp1, temp1 + MAX, 0);
	fill(temp2, temp2 + MAX, 0);

	income[start] = money[start];

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < graph[j].size(); k++) {
				int nextNode = graph[j][k].first;
				int nextCost = graph[j][k].second;

				if (income[j] != -INF && income[nextNode] < income[j] + nextCost + money[nextNode]) {
					income[nextNode] = income[j] + nextCost + money[nextNode];

					if (i == 99) {
						for (int k = 0; k < N; k++)
							temp1[k] = income[k];
					}
					if (i == 98) {
						for (int k = 0; k < N; k++)
							temp2[k] = income[k];
					}
				}
			}
		}
	}

	vector<ll> cycleNode;

	for (int i = 0; i < N; i++) {
		if (temp1[i] != temp2[i])
			cycleNode.push_back(i);
	}

	bool flag = false;

	for (int i = 0; i < cycleNode.size(); i++) {
		fill(check, check + MAX, false);

		if (bfs(cycleNode[i], des) == true) {
			flag = true;
			break;
		}
	}

	if (income[des] == -INF) {
		cout << "gg" << endl;
		return 0;
	}
	if (flag == true) {
		cout << "Gee" << endl;
		return 0;
	}
	else
		cout << income[des] << endl;


	return 0;
}