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

int arr[1000001];

void eratos() {
	for (int i = 2; i <= 1000000; i++)
		arr[i] = i;

	for (int i = 2; i <= 1000000; i++) {
		if (arr[i] == 0)
			continue;

		for (int j = i + i; j <= 1000000; j += i)
			arr[j] = 0;
	}
}

int main() {
	eratos();
	fastio;

	while (1) {
		int n;
		cin >> n;

		if (n == 0)
			break;

		int left = 3;
		int right = n - 3;

		while (left <= right) {
			if (arr[left] != 0 && arr[right] != 0)
				if (left + right == n)
					break;

			if (left + right < n)
				left += 2;
			else
				right -= 2;
		}

		if (left > right)
			cout << "Goldbach's conjecture is wrong." << endl;
		else 
			cout << n << " = " << left << " + " << right << '\n';
	}
}