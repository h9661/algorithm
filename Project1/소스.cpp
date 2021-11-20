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
	fastio;
	int N;
	cin >> N;

	int k;
	cin >> k;
	
	if (N == 1) {
		cout << 0 << endl;
		return 0;
	}

	vector<int> arr(N - 1, 0);
	for (int i = 0; i < N - 1; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());

	bool flag = false;
	int ans = 0;

	while (1) {
		for (int i = 0; i < N - 1; i++) {
			if (arr[i] >= k)
				break;

			if (i == N - 2)
				flag = true;
		}

		if (flag == true)
			break;

		sort(arr.begin(), arr.end());
		
		arr[N - 2] -= 1;
		k += 1;
		ans++;


	}

	cout << ans << endl;
}