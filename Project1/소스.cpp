#include <bits/stdc++.h>
#pragma warning (disable : 4996)
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

int main() {
	fastio;
	int tc;
	cin >> tc;

	while (tc--) {
		int N;
		cin >> N;

		vector<pii> arr(N, { 0, 0 });

		for (int i = 0; i < N; i++)
			cin >> arr[i].first >> arr[i].second;

		sort(arr.begin(), arr.end());

		int count = 1;

		int a = arr[0].first;
		int b = arr[0].second;

		for (int i = 1; i < N; i++) {
			if (b > arr[i].second) {
				a = arr[i].first;
				b = arr[i].second;
				count++;
			}
		}

		cout << count << endl;
	}
}