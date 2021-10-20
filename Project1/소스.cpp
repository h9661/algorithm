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
	int X;
	cin >> X;

	int arr[7];
	fill(arr, arr + 7, 0);

	int index = 6;

	while (X > 0) {
		if (X % 2 == 1) {
			arr[index] = 1;
		}
		else {
			arr[index] = 0;
		}

		X /= 2;
		index--;
	}

	int count = 0;

	for (int i = 0; i < 7; i++) {
		if (arr[i])
			count++;
	}

	cout << count << endl;
}