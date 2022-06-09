#include <bits/stdc++.h>
#define endl '\n'
#define ii pair<long long, long long>
using namespace std;

const int MAX = 64;
int graph[MAX][MAX];

vector<char> ansvec;

void DC(int row, int col, int N) {
	int temp = graph[row][col];
	bool contFlag = false;

	for (int i = row; i < N + row; i++) {
		for (int j = col; j < N + col; j++) {
			if (graph[i][j] != temp) {
				contFlag = true;
				break;
			}
		}
	}

	if (contFlag) {
		ansvec.push_back('(');
		DC(row, col, N / 2);
		DC(row, col + N / 2, N / 2);
		DC(row + N / 2, col, N / 2);
		DC(row + N / 2, col + N / 2, N / 2);
		ansvec.push_back(')');
	}
	else {
		if (temp == 1)
			ansvec.push_back('1');
		else
			ansvec.push_back('0');
	}
}

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char x;
			cin >> x;
			graph[i][j] = (int)x - 48;
		}
	}

	DC(0, 0, N);

	for (auto i : ansvec)
		cout << i;
}