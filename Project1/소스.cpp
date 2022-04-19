#include <bits/stdc++.h>
using namespace std;

const int MAX = 129;
int paper[MAX][MAX];
int white = 0;
int blue = 0;

bool checking(int n, int x, int y) {
	int temp = paper[y][x];

	for (int i = y; i < n + y; i++) {
		for (int j = x; j < n + x; j++) {
			if (paper[i][j] != temp)
				return false;
		}
	}

	return true;
}

void devide_paper(int n, int x, int y) {
	if (!checking(n, x, y)) {
		devide_paper(n / 2, x, y);
		devide_paper(n / 2, x + n / 2, y);
		devide_paper(n / 2, x, y + n / 2);
		devide_paper(n / 2, x + n / 2, y + n / 2);
	}
	else {
		if (paper[y][x] == 1)
			blue++;
		else
			white++;
	}
}

int main() {
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			cin >> paper[i][j];
	}

	devide_paper(N, 1, 1);

	cout << white << endl;
	cout << blue << endl;
}