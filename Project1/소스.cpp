#include <bits/stdc++.h>
#pragma warning (disable : 4996)
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

const int MAX = 100 + 1;
int field[MAX][MAX];

int main() {
	fastio;
	int N;
	cin >> N;
	int K;
	cin >> K;
	for (int i = 0; i < K; i++) {
		int y, x;
		cin >> y >> x;

		field[y - 1][x - 1] = 1;
	}

	vector<pair<int, int>> snakeBody;
	pair<int, int> snakeHead = { 0, 0 };
	pair<int, int> MovingDir[4] = {
		{0, 1},
		{1, 0},
		{0, -1},
		{-1, 0},
	};

	int L;
	cin >> L;
	queue<pair<int, char>> changeDir;
	for (int i = 0; i < L; i++) {
		int time;
		char Dir;
		cin >> time >> Dir;

		changeDir.push({ time, Dir });
	}

	int time = 0;
	int direction = 0;

	while (1) {
		int tailTempY = snakeHead.first;
		int tailTempX = snakeHead.second;
		snakeHead.first += MovingDir[direction].first;
		snakeHead.second += MovingDir[direction].second;
		time += 1;

		if (snakeHead.first < 0 || snakeHead.first > N - 1 || snakeHead.second < 0 || snakeHead.second > N - 1)
			break;

		for (int i = 0; i < snakeBody.size(); i++) {
			if (snakeHead.first == snakeBody[i].first && snakeHead.second == snakeBody[i].second) {
				goto EXIT;
			}
		}

		if (field[snakeHead.first][snakeHead.second] == 1) {
			snakeBody.insert(snakeBody.begin(), { tailTempY, tailTempX });
			field[snakeHead.first][snakeHead.second] = 0;
		}
		else if (field[snakeHead.first][snakeHead.second] == 0) {
			if (snakeBody.size() >= 1) {
				snakeBody.pop_back();
				snakeBody.insert(snakeBody.begin(), { tailTempY, tailTempX });
			}
		}

		if (changeDir.size() > 0) {
			if (time == changeDir.front().first) {
				if (changeDir.front().second == 'D') {
					direction += 1;
					if (direction > 3)
						direction = 0;
				}
				else {
					direction -= 1;
					if (direction < 0)
						direction = 3;
				}

				changeDir.pop();
			}
		}
	}

EXIT:

	cout << time << endl;
}