#include <bits/stdc++.h>
#define endl '\n'
#define ii pair<int, int>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N;
	cin >> N;

	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;

		if (x == 0) {
			if (pq.size() == 0)
				cout << 0 << endl;
			else {
				cout << pq.top() << endl;
				pq.pop();
			}
		}
		else {
			pq.push(x);
		}
	}
}