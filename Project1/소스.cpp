#include <bits/stdc++.h>
#define endl '\n'
#define ll pair<long long, long long>
#define ii pair<int, int>
using namespace std;

const int MAX = 20;
int graph[MAX][MAX];
bool check[MAX][MAX];
int N;
int Y[4] = { -1, 1, 0, 0 };
int X[4] = { 0, 0, -1, 1 };

struct cmp {
	bool operator()(pair<int, ii> a, pair<int, ii> b) {
		if (a.first != b.first)
			return a.first > b.first;
		else {
			if (a.second.first != b.second.first)
				return a.second.first > b.second.first;
			else
				return a.second.second > b.second.second;
		}
	}
};

int bfs() {
	queue<pair<int, ii>> q;
	int t = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (graph[i][j] == 9) {
				q.push({ 0,  {i,j} });
				graph[i][j] = 0;
				check[i][j] = true;
			}
		}
	}
	
	int size = 2;
	int count = 0;
	int eat_count = 0;

	int pos_y = q.front().second.first;
	int pos_x = q.front().second.second;

	while(1) {
		priority_queue<pair<int, ii>, vector<pair<int, ii>>, cmp> minHeap;

		while (!q.empty()) {
			int cy = q.front().second.first;
			int cx = q.front().second.second;
			int ct = q.front().first;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int ny = cy + Y[i];
				int nx = cx + X[i];
				int nt = ct + 1;

				if (0 <= ny and ny < N and 0 <= nx and nx < N) {
					if (check[ny][nx] == false and graph[ny][nx] <= size) {
						q.push({ nt, {ny, nx} });
						check[ny][nx] = true;

						if (0 < graph[ny][nx] and graph[ny][nx] < size)
							minHeap.push({ nt, {ny, nx} });
					}
				}
			}
		}

		if (minHeap.empty())
			break;
		else {
			while (!q.empty())
				q.pop();

			memset(check, false, sizeof(check));
			count++;
			eat_count++;
			if (count >= size) {
				size++;
				count = 0;
			}
			t += minHeap.top().first;

			pos_y = minHeap.top().second.first;
			pos_x = minHeap.top().second.second;

			while (!minHeap.empty())
				minHeap.pop();

			graph[pos_y][pos_x] = 0;
			q.push({ 0, {pos_y, pos_x} });
			check[pos_y][pos_x] = true;
		}
	}

	return t;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cin >> graph[i][j];
	}

	cout << bfs() << endl;
}