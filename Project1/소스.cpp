#include <bits/stdc++.h>
#define endl '\n'
#define ii pair<int, int>
using namespace std;

int countzero = 0;
int countone = 0;
int countminusone = 0;
int graph[3000][3000];

void DC(int row, int col, int N) {
	bool continueflag = false;
	int temp = graph[row][col];

	for (int i = row; i < N + row; i++) {
		for (int j = col; j < N + col; j++) {
			if (temp != graph[i][j]) {
				continueflag = true;
				break;
			}
		}
	}

	if (continueflag) {
		DC(row, col, N / 3);
		DC(row, col + N / 3, N / 3);
		DC(row, col + (N / 3) * 2, N / 3);
		DC(row + N / 3, col, N / 3);
		DC(row + N / 3, col + N / 3, N / 3);
		DC(row + N / 3, col + (N / 3) * 2, N / 3);
		DC(row + (N / 3) * 2, col, N / 3);
		DC(row + (N / 3) * 2, col + N / 3, N / 3);
		DC(row + (N / 3) * 2, col + (N / 3) * 2, N / 3);
	}
	else {
		if (temp == 1)
			countone++;
		else if (temp == 0)
			countzero++;
		else
			countminusone++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			cin >> graph[i][j];
	}


	DC(1, 1, N);

	cout << countminusone << endl;
	cout << countzero << endl;
	cout << countone << endl;
}