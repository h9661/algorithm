#include <bits/stdc++.h>
using namespace std;

bool solvTest() {
	int n;
	cin >> n;

	vector<int> arr(n, 0);
	vector<bool> used(n + 1, false);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end(),
		[](int a, int b) {
			return a > b;
		}
	);

	bool check = true;

	for (int i = 0; i < n; i++) {
		int x = arr[i];

		while (x > n or used[x])
			x /= 2;

		if (x > 0)
			used[x] = true;
		else
			check = false;
	}

	return check;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		if (solvTest())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}