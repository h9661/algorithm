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
	string s;
	cin >> s;

	vector<int> arr;

	for (int i = 0; i < s.size(); i++)
		arr.push_back(s[i] - '0');

	sort(arr.begin(), arr.end());

	int sum = 0;
	for (int i = 0; i < arr.size(); i++)
		sum += arr[i];

	if (arr[0] || sum % 3)
		cout << -1 << endl;
	else {
		for (int i = arr.size() - 1; i >= 0; i--)
			cout << arr[i];
	}
}