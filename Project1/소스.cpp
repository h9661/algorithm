#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAX = 100001;
bool check[MAX];

int main() {
	int N, K;
	cin >> N >> K;

	queue<pair<int, int>> q;
	q.push({ N, 0 });
	check[N] = true;

	int min_ans = 1e9;

	while (!q.empty()) {
		int curN = q.front().first;
		int curC = q.front().second;
		q.pop();

		if (curN == K)
			min_ans = min(min_ans, curC);


		if (2 * curN <= 100000 && 2 * curN >= 0) {
			if (check[2 * curN] == false) {
				q.push({ 2 * curN, curC + 1 });
				check[2 * curN] = true;
			}
		}

		if (curN + 1 <= 100000) {
			if (check[curN + 1] == false) {
				q.push({ curN + 1, curC + 1 });
				check[1 + curN] = true;
			}
		}

		if (curN - 1 >= 0) {
			if (check[curN - 1] == false) {
				q.push({ curN - 1, curC + 1 });
				check[curN - 1] = true;
			}
		}
	}

	cout << min_ans << endl;
}