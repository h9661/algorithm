#include <bits/stdc++.h>
#define endl '\n'
#define ii pair<long long, long long>
using namespace std;

const int MAX = 128;
int graph[MAX][MAX];
int one = 0;
int zero = 0;

void DC(int row, int col, int N) {
	int temp = graph[row][col];
	bool contFlag = false;

	for (int i = row; i < row + N; i++)
		for (int j = col; j < col + N; j++)
			if (graph[i][j] != temp)
				contFlag = true;

	if (contFlag) {
		DC(row, col, N / 2);
		DC(row, col + N / 2, N / 2);
		DC(row + N / 2, col, N / 2);
		DC(row + N / 2, col + N / 2, N / 2);
	}
	else {
		if (temp == 0)
			zero++;
		else
			one++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
		}
	}

	DC(0, 0, N);
	cout << zero << endl;
	cout << one << endl;
}