#include <vector>
#include <iostream>
#define endl '\n'
#define ll pair<long long, long long>
#define ii pair<int, int>
using namespace std;

const int MAX = 9;
vector<vector<int>> sudokuBoard(MAX, vector<int>(MAX));
vector<vector<bool>> check(MAX, vector<bool>(MAX));

bool CheckRow(int row, int columm, int number) {
	for (int i = 0; i < 9; i++) {
		if (columm == i)
			continue;

		if (number == sudokuBoard[row][i])
			return false;
	}

	return true;
}

bool CheckColumm(int row, int columm, int number) {
	for (int i = 0; i < 9; i++) {
		if (row == i)
			continue;

		if (number == sudokuBoard[i][columm])
			return false;
	}

	return true;
}

bool CheckSquare(int row, int columm, int number) {
	int newRow = row / 3;
	int newColumm = columm / 3;

	for (int i = newRow * 3; i < (newRow + 1) * 3; i++) {
		for (int j = newColumm * 3; j < (newColumm + 1) * 3; j++) {
			if (row == newRow && columm == newColumm)
				continue;

			if (number == sudokuBoard[i][j])
				return false;
		}
	}

	return true;
}

void dfs(int pos) {
	if (pos == 81) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++)
				cout << sudokuBoard[i][j] << " ";
			cout << endl;
		}

		exit(0);
	}
	else {
		int row = pos / 9;
		int columm = pos % 9;

		if (check[row][columm] == false) {
			check[row][columm] = true;

			if (sudokuBoard[row][columm] == 0) {
				for (int i = 1; i <= 9; i++) {
					if (CheckRow(row, columm, i) && CheckColumm(row, columm, i) && CheckSquare(row, columm, i)) {
						sudokuBoard[row][columm] = i;

						dfs(pos + 1);

						sudokuBoard[row][columm] = 0;
					}
				}
			}
			else
				dfs(pos + 1);

			check[row][columm] = false;
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			cin >> sudokuBoard[i][j];

	dfs(0);
}