#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define ii pair<ll, ll>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> arr;
	arr.resize(N);

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());

	int ans = 0;

	for (int i = 0; i < N; i++) {
		if (arr[i] * (N - i) >= arr[N - 1]) {
			ans = max(ans, arr[i] * (N - i));
		}
	}

	cout << ans << endl;
}