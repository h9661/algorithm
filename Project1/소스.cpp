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
	int N, M;
	cin >> N >> M;

	vector<int> arr(M, 0);
	for (int i = 0; i < M; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());

	int ans = 0;

	int temp1 = 0;
	int temp2 = 0;

	for (int i = 0; i < M; i++) {
		if (N < M - i) {
			if (ans < N * arr[i]) {
				ans = N * arr[i];
				temp1 = i;
			}
		}
		else {
			if (ans < (M - i) * arr[i]) {
				ans = (M - i) * arr[i];
				temp2 = i;
			}
		}
	}

	if ((M - temp1) * arr[temp1] == ans)
		cout << arr[temp1] << " ";
	else
		cout << arr[temp2] << " ";

	cout << ans << endl;

}