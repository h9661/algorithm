#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long int
const int MAX = 51;

int graph[MAX][MAX];
int check[MAX][MAX];
map<int, pair<int, int>> mp;
int Y[4] = { -1, 1, 0, 0 };
int X[4] = { 0, 0, -1, 1 };
int N, L, R;
int g_number = 0;

void Input() {
	cin >> N >> L >> R;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			cin >> graph[i][j];
	}
}

void NumberingMap() {
	int number = 1;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (check[i][j] == 0) {
				queue<pair<int, int>> q;

				int sum = 0;
				int count = 0;

				q.push({ i, j });
				check[i][j] = number;
				count += 1;
				sum += graph[i][j];


				while (!q.empty()) {
					int cy = q.front().first;
					int cx = q.front().second;
					q.pop();

					for (int i = 0; i < 4; i++) {
						int ny = cy + Y[i];
						int nx = cx + X[i];

						if (ny >= 1 && ny <= N && nx >= 1 && nx <= N && check[ny][nx] == 0) {
							if (abs(graph[ny][nx] - graph[cy][cx]) >= L && abs(graph[ny][nx] - graph[cy][cx]) <= R) {
								q.push({ ny, nx });
								count++;
								check[ny][nx] = number;
								sum += graph[ny][nx];
							}
						}
					}
				}

				mp[number] = { sum, count };
				number++;
			}
		}
	}

	g_number = number;
}

void TransferPeople() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			graph[i][j] = mp[check[i][j]].first / mp[check[i][j]].second;
		}
	}
}

void Reset() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			check[i][j] = 0;
	}

	mp.clear();
}

void PrintCheck() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			cout << check[i][j] << " ";
		cout << endl;
	}
}

void PrintGraph() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	Input();
	int ans = 0;

	while (1) {
		NumberingMap();
		TransferPeople();

		if (check[N][N] == N * N)
			break;

		ans++;


		Reset();
	}
	int ans = 0;

	while (1) {
		NumberingMap();
		TransferPeople();

		if (check[N][N] == N * N)
			break;

		ans++;


		Reset();
	}
	store.push_back(temp2);
	store.push_back(temp3);

	sort(store.begin(), store.end());

	for (auto i : store)
		cout << i << " ";
	store.push_back(temp2);
	store.push_back(temp3);

	sort(store.begin(), store.end());

	for (auto i : store)
		cout << i << " ";
	store.push_back(temp2);
	store.push_back(temp3);

	sort(store.begin(), store.end());

	for (auto i : store)
		cout << i << " ";
	store.push_back(temp2);
	store.push_back(temp3);

	sort(store.begin(), store.end());

	for (auto i : store)
		cout << i << " ";

	cout << ans << endl;
}