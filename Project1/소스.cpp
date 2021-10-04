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

int N;
int maxValue = -987654321;
int minValue = 987654321;
vector<int> opCount(4, 0);
vector<int> arr(101, 0);
int op[101];

void dfs(int x) {
	if (x == N - 1) {
		int temp = 0;

		for (int i = 0; i < N - 1; i++) {
			if		(op[i] == 0) {
				if (i == 0)
					temp = arr[i] + arr[i + 1];
				else
					temp = temp + arr[i + 1];
			}
			else if (op[i] == 1) {
				if (i == 0)
					temp = arr[i] - arr[i + 1];
				else
					temp = temp - arr[i + 1];
			}
			else if (op[i] == 2) {
				if (i == 0)
					temp = arr[i] * arr[i + 1];
				else
					temp = temp * arr[i + 1];
			}
			else if (op[i] == 3) {
				if (i == 0)
					temp = arr[i] / arr[i + 1];
				else
					temp = temp / arr[i + 1];
			}
		}

		maxValue = max(maxValue, temp);
		minValue = min(minValue, temp);

		return;
	}

	for (int i = 0; i < 4; i++) {
		if (opCount[i] > 0) {
			opCount[i] -= 1;

			op[x] = i;
			dfs(x + 1);

			opCount[i] += 1;
		}
	}
}


int main() {
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int i = 0; i < 4; i++)
		cin >> opCount[i];


	dfs(0);

	cout << maxValue << endl;
	cout << minValue << endl;

	return 0;
}