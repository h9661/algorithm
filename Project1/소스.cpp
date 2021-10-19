#include <bits/stdc++.h>
#pragma warning (disable : 4996)
#pragma warning (disable : 6385)
#pragma warning (disable : 6386)
#pragma warning (disable : 6200)
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

int main() {
	int L;
	cin >> L;

	vector<int> arr(L, 0);

	for (int i = 0; i < L; i++)
		cin >> arr[i];

	int n;
	cin >> n;

	sort(arr.begin(), arr.end());

	int min_value = 0;
	int max_value = arr[0];
	bool flag = false;

	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] <= n)
			min_value = arr[i];

		if (arr[i] >= n && flag == false) {
			max_value = arr[i];
			flag = true;
		}
	}

	int ans = 0;

	for (int i = min_value + 1; i <= n; i++) {
		for (int j = n; j <= max_value - 1; j++) {
			if (i == j)
				continue;

			ans++;
		}
	}

	cout << ans << endl;

	return 0;
}