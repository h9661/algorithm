#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAX_K = 15;
const int MAX_N = 15;
int people[MAX_K][MAX_N];

int main() {
	int T;
	cin >> T;

	for (int j = 0; j < 15; j++) {
		people[0][j] = j + 1;
	}

	for (int k = 1; k < 15; k++) {
		for (int j = 0; j < 15; j++) {
			for (int i = 0; i <= j; i++) {
				people[k][j] += people[k - 1][i];
			}
		}
	}

	while (T--) {
		int k, n; cin >> k >> n;

		cout << people[k][n - 1] << endl;
	}
}