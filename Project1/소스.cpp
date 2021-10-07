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

int N, M;

void Transfrom(vector<string>& matrix, int row, int col) {
	for (int i = row; i < row + 3; i++) {
		for (int j = col; j < col + 3; j++) {
			if (matrix[i][j] == '0')
				matrix[i][j] = '1';
			else
				matrix[i][j] = '0';
		}
	}
}

int main() {
	cin >> N >> M;

	vector<string> matrix1;
	vector<string> matrix2;

	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;

		matrix1.push_back(temp);
	}
	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;

		matrix2.push_back(temp);
	}
	int count = 0;

	for (int i = 0; i <= N - 3; i++) {
		for (int j = 0; j <= M - 3; j++) {
			if (matrix1[i][j] != matrix2[i][j]) {
				Transfrom(matrix1, i, j);
				count++;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (matrix1[i][j] != matrix2[i][j]) {
				cout << -1 << endl;
				return 0;
			}
		}
	}

	cout << count << endl;
}