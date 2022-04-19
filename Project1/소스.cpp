#include <iostream>
using namespace std;

int memo[5001];
const int INF = 1e8;
int main() {
	int N;
	cin >> N;

	memo[0] = 0;
	memo[1] = INF;
	memo[2] = INF;
	memo[3] = 1;
	memo[4] = INF;
	memo[5] = 1;

	for (int i = 6; i <= 5000; i++) {
		memo[i] = min(memo[i - 3] + 1, memo[i - 5] + 1);
	}

	if (memo[N] >= 50000)
		cout << -1 << endl;
	else
		cout << memo[N] << endl;
}