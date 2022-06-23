#include <bits/stdc++.h>
#define endl '\n'
#define ll pair<long long, long long>
#define ii pair<int, int>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		priority_queue<ii, vector<ii>, greater<ii>> minHeap;
		priority_queue<ii, vector<ii>, less<ii>> maxHeap;
		vector<bool> check(1000000, false);
		int k;
		cin >> k;

		for (int i = 0; i < k; i++) {
			char op;
			int n;
			cin >> op >> n;

			if (op == 'I') {
				minHeap.push({ n, i });
				maxHeap.push({ n, i });
				check[i] = true;
			}
			else {
				if (n == 1) {
					while (!maxHeap.empty() and !check[maxHeap.top().second])
						maxHeap.pop();

					if (!maxHeap.empty()) {
						check[maxHeap.top().second] = false;
						maxHeap.pop();
					}
				}
				else {
					while (!minHeap.empty() and !check[minHeap.top().second])
						minHeap.pop();

					if (!minHeap.empty()) {
						check[minHeap.top().second] = false;
						minHeap.pop();
					}
				}
			}
		}

		while (!maxHeap.empty() and !check[maxHeap.top().second])
			maxHeap.pop();
		while (!minHeap.empty() and !check[minHeap.top().second])
			minHeap.pop();

		if (minHeap.empty() and maxHeap.empty())
			cout << "EMPTY" << endl;
		else
			cout << maxHeap.top().first << " " << minHeap.top().first << endl;
	}
}