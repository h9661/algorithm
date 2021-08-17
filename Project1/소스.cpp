#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define ii pair<ll, ll>
using namespace std;

int main() {
	int n;
	cin >> n;

	int k = 1000 - n;

	int arr[6] = { 500, 100, 50, 10, 5, 1 };

	int count = 0;

	for (int i = 0; i < 6; i++) {
		while (k >= arr[i]) {
			k -= arr[i];
			count++;
		}
	}

	cout << count << endl;

	return 0;
}