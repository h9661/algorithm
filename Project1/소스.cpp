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
	fastio;

	int arr[1000000];
	int test_num, day_num;

	cin >> test_num;

	ll profit_sum = 0;
	int max_stock = 0;

	while (test_num--) {
		cin >> day_num;

		for (int day = 0; day < day_num; day++)
			cin >> arr[day];

		profit_sum = 0;
		max_stock = 0;

		for (int day = day_num - 1; day >= 0; day--) {
			if (arr[day] < max_stock)
				profit_sum += (max_stock - arr[day]);
			else
				max_stock = arr[day];
		}

		cout << profit_sum << endl;
	}
}