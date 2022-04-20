#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	vector<int> a(N);
	for (int i = 0; i < N; i++)
		cin >> a[i];

	int count = 0;
	int startIdx = 0;

	for (int i = 0; i < N; i++) {
		if (K < a[i])
			break;

		startIdx = i;
	}

	for (int i = startIdx; K != 0;) {
		if (K >= a[i]) {
			K -= a[i];
			count++;
		}
		else
			i--;
	}

	cout << count << endl;
}