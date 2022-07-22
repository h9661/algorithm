#include <bits/stdc++.h>
#define endl '\n'
#define ll pair<long long, long long>
#define ii pair<int, int>
using namespace std;

const int MAX = 8;
int N, M;
ii graph[MAX][MAX];
bool visited[MAX][MAX];
int cctvCount = 0;
vector<int> resultArr;

void Up(int y, int x) {
	for (int i = y; i >= 0; i--) {
		if (graph[i][x].first == 6)
			break;
		else if (graph[i][x].first == 0)
			graph[i][x].first = 9;
		else
			continue;
	}
}

void Down(int y, int x) {
	for (int i = y; i < N; i++) {
		if (graph[i][x].first == 6)
			break;
		else if (graph[i][x].first == 0)
			graph[i][x].first = 9;
		else
			continue;
	}
}

void Left(int y, int x) {
	for (int i = x; i >= 0; i--) {
		if (graph[y][i].first == 6)
			break;
		else if (graph[y][i].first == 0)
			graph[y][i].first = 9;
		else
			continue;
	}
}

void Right(int y, int x) {
	for (int i = x; i < M; i++) {
		if (graph[y][i].first == 6)
			break;
		else if (graph[y][i].first == 0)
			graph[y][i].first = 9;
		else
			continue;
	}
}

void dfs(int count, int pos) {
	if (cctvCount == count) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (graph[i][j].first == 1) {
					if (graph[i][j].second == 1)
						Up(i, j);
					else if (graph[i][j].second == 2)
						Right(i, j);
					else if (graph[i][j].second == 3)
						Down(i, j);
					else
						Left(i, j);
				}

				if (graph[i][j].first == 2) {
					if (graph[i][j].second == 1) {
						Up(i, j);
						Down(i, j);
					}
					else {
						Left(i, j);
						Right(i, j);
					}
				}

				if (graph[i][j].first == 3) {
					if (graph[i][j].second == 1) {
						Up(i, j);
						Right(i, j);
					}
					else if (graph[i][j].second == 2) {
						Right(i, j);
						Down(i, j);
					}
					else if (graph[i][j].second == 3) {
						Down(i, j);
						Left(i, j);
					}
					else {
						Left(i, j);
						Up(i, j);
					}
				}

				if (graph[i][j].first == 4) {
					if (graph[i][j].second == 1) {
						Left(i, j);
						Up(i, j);
						Right(i, j);
					}
					else if (graph[i][j].second == 2) {
						Up(i, j);
						Right(i, j);
						Down(i, j);
					}
					else if (graph[i][j].second == 3) {
						Right(i, j);
						Down(i, j);
						Left(i, j);
					}
					else {
						Down(i, j);
						Left(i, j);
						Up(i, j);
					}
				}

				if (graph[i][j].first == 5) {
					Up(i, j);
					Down(i, j);
					Left(i, j);
					Right(i, j);
				}
			}
		}

		int result = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				//cout << graph[i][j].second << " ";

				if (graph[i][j].first == 0)
					result++;

				if (graph[i][j].first == 9)
					graph[i][j].first = 0;
			}
			//cout << endl;
		}
		//cout << "---------------------------------" << endl;


		resultArr.push_back(result);
	}
	else {
		for (int i = pos; i < N * M; i++) {
			int y = i / M;
			int x = i % M;

			if (visited[y][x] == false) {
				visited[y][x] = true;

				if (graph[y][x].first == 1) {
					for (int face = 1; face <= 4; face++) {
						graph[y][x].second = face;
						dfs(count + 1, i + 1);
					}
				}
				else if (graph[y][x].first == 2) {
					for (int face = 1; face <= 2; face++) {
						graph[y][x].second = face;
						dfs(count + 1, i + 1);
					}
				}
				else if (graph[y][x].first == 3) {
					for (int face = 1; face <= 4; face++) {
						graph[y][x].second = face;
						dfs(count + 1, i + 1);
					}
				}
				else if (graph[y][x].first == 4) {
					for (int face = 1; face <= 4; face++) {
						graph[y][x].second = face;
						dfs(count + 1, i + 1);
					}
				}

				visited[y][x] = false;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j].first;
			graph[i][j].second = 0;

			if (graph[i][j].first >= 1 and graph[i][j].first <= 4)
				cctvCount++;
		}
	}
	
	//cout << "------------------------------------------" << endl;
	dfs(0, 0);

	cout << *min_element(resultArr.begin(), resultArr.end()) << endl;
}