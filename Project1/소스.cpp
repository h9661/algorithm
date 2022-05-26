#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	int tc;
	cin >> tc;

	while (tc--) {
		int n;
		cin >> n;

		vector<int> arr(n, 0);
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		int sum = 0;
		for (int i = 0; i < n; i++)
			sum += arr[i] - *min_element(arr.begin(), arr.end());

		cout << sum << endl;
	}
}