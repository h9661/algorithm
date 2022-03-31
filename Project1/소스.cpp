#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;

		pq.push(temp);
	}

	if (n >= 2) {
		int sum = 0;

		for (int i = 0; i < n - 1; i++) {
			int a = pq.top(); pq.pop();
			int b = pq.top(); pq.pop();
			sum += a + b;
			pq.push(a + b);
		}

		cout << sum << endl;
	}
	else
		cout << 0 << endl;
}