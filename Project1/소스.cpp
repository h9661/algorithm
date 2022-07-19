#include <bits/stdc++.h>
#define endl '\n'
#define ll pair<long long, long long>
#define ii pair<int, int>
using namespace std;

const int MAX = 500 + 1;
int arr[MAX][MAX];

int main() {
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = N - 1; i >= 1; i--) {
		for (int j = 1; j <= i; j++) {
			arr[i][j] += max(arr[i + 1][j], arr[i + 1][j + 1]);
		}
	}

	cout << arr[1][1] << endl;
}