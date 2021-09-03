#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

int islandMap[15][15];
bool check[15][15];
int N, M;
int Y[4] = { -1, 1, 0, 0 };
int X[4] = { 0, 0, -1, 1 };

int island_num = 1;

const int MAX = 10;
vector<pii> graph[MAX];
bool pqCheck[MAX];

void bfs(int i,int j) {
	queue<pii> q;
	q.push({ i, j });
	check[i][j] = true;
	islandMap[i][j] = island_num;

	while (!q.empty()) {
		int currentY = q.front().first;
		int currentX = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextY = Y[i] + currentY;
			int nextX = X[i] + currentX;

			if (nextY >= 1 && nextY <= N && nextX >= 1 && nextX <= M && check[nextY][nextX] == false && islandMap[nextY][nextX] != 0) {
				q.push({ nextY, nextX });
				check[nextY][nextX] = true;
				islandMap[nextY][nextX] = island_num;
			}
		}
	}

	island_num++;
}

pii IslandSearchLeft(int i, int j, int startIsland) {
	int count = 0;

	for (int pos = j - 1; pos >= 1; pos--) {
		if (islandMap[i][pos] == 0) {
			count++;
			continue;
		}

		if (islandMap[i][pos] == startIsland)
			return { -1, -1 };
		else
			return { count, islandMap[i][pos] };
	}

	return { -1, -1 };
}

pii IslandSearchRight(int i, int j, int startIsland) {
	int count = 0;

	for (int pos = j + 1; pos <= M; pos++) {
		if (islandMap[i][pos] == 0) {
			count++;
			continue;
		}

		if (islandMap[i][pos] == startIsland)
			return{ -1, -1 };
		else
			return { count,islandMap[i][pos] };
	}

	return { -1, -1 };
}

pii IsIandSearchUp(int i, int j, int startIsland) {
	int count = 0;

	for (int pos = i - 1; pos >= 1; pos--) {
		if (islandMap[pos][j] == 0) {
			count++;
			continue;
		}

		if (islandMap[pos][j] == startIsland)
			return { -1, -1 };
		else
			return { count, islandMap[pos][j] };
	}

	return { -1, -1 };
}

pii IslandSearchDown(int i, int j, int startIsland) {
	int count = 0;

	for (int pos = i + 1; pos <= N; pos++) {
		if (islandMap[pos][j] == 0) {
			count++;
			continue;
		}

		if (islandMap[pos][j] == startIsland)
			return { -1, -1 };
		else
			return { count, islandMap[pos][j] };
	}

	return { -1, -1 };
}

int main() {
	cin >> N >> M;


/*──── 섬 번호 부여하기 ─────*/
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++)
			cin >> islandMap[i][j];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (islandMap[i][j] != 0 && check[i][j] == false)
				bfs(i, j);
		}
	}
//────────────────────
	// 그래프에 노드와 비용 넣기
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (islandMap[i][j] == 0)
				continue;

			int startIsland = islandMap[i][j];

			pii temp;
			temp = IslandSearchLeft(i, j, startIsland);
			if (temp.first > 1)
				graph[startIsland].push_back({ temp.first, temp.second });


			temp = IslandSearchRight(i, j, startIsland);
			if (temp.first > 1)
				graph[startIsland].push_back({ temp.first, temp.second });


			temp = IsIandSearchUp(i, j, startIsland);
			if (temp.first > 1)
				graph[startIsland].push_back({ temp.first, temp.second });


			temp = IslandSearchDown(i, j, startIsland);
			if (temp.first > 1)
				graph[startIsland].push_back({ temp.first, temp.second });

		}
	}

	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({ 0, 1 });

	int ans = 0;

	while (!pq.empty()) {
		int nowCost = pq.top().first;
		int nowNode = pq.top().second;
		pq.pop();

		if (pqCheck[nowNode] == true)
			continue;
		pqCheck[nowNode] = true;
		ans += nowCost;

		for (int i = 0; i < graph[nowNode].size(); i++) {
			int nextCost = graph[nowNode][i].first;
			int nextNode = graph[nowNode][i].second;

			if (pqCheck[nextNode] == false)
				pq.push({ nextCost, nextNode });
		}
	}

	for (int i = 1; i <= island_num - 1; i++) {
		if (pqCheck[i] == false) {
			cout << "-1" << endl;
			return 0;
		}
	}

	if (ans == 0)
		cout << "-1" << endl;
	else
		cout << ans << endl;
}