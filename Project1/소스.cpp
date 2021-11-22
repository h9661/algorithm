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

int arrows[1000001];

int main() {
	fastio;
	int N;
	cin >> N;
	vector<int> arr(N, 0);

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int ans = 0;

	for (int i = 0; i < N; i++) {
		if (arrows[arr[i]] > 0) {
			arrows[arr[i]]--;
			arrows[arr[i] - 1]++;
			continue;
		}
		else {
			arrows[arr[i] - 1]++;
			ans++;
		}
	}

	cout << ans << endl;
}