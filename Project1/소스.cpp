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
	int M;
	cin >> M;

	vector<int> arr(4, 0);
	arr[1] = 1;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		int temp = arr[b];
		arr[b] = arr[a];
		arr[a] = temp;
	}

	for (int i = 1; i <= 3; i++) {
		if (arr[i] == 1) {
			cout << i << endl;
			return 0;
		}
	}

	cout << -1 << endl;
}