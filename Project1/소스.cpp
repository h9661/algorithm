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
	int n;
	cin >> n;

	vector<int> arr(n, 0);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int sum = accumulate(arr.begin(), arr.end(), 0);

	sum -= *max_element(arr.begin(), arr.end());

	cout << sum << endl;
}