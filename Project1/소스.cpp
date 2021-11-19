#include <bits/stdc++.h>
#pragma warning (disable : 4996)
#pragma warning (disable : 6385)
#pragma warning (disable : 6386)
#pragma warning (disable : 6200)
#pragma warning (disable : 26812)
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> arr(2 * n, 0);

	for (int i = 0; i < 2 * n; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());

	int ans = 2e9;

	for (int i = 0; i < n; i++) {
		ans = min(ans, arr[i] + arr[2 * n - (i + 1)]);
	}

	cout << ans << endl;
}