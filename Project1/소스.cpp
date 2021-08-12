#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define ii pair<int, int>
using namespace std;

const int MAX = 10000;
pair <double, double> arr[MAX + 3];

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i].first >> arr[i].second;

	arr[N].first = arr[0].first;
	arr[N].second = arr[0].second;

	long double sum1 = 0;
	long double sum2 = 0;

	for (int i = 0; i < N; i++) {
		sum1 += arr[i].first * arr[i + 1].second;
		sum2 += arr[i].second * arr[i + 1].first;
	}

	long double ans = abs(sum1 - sum2) / 2.0;

	cout.setf(ios::fixed);
	cout.precision(1);

	cout << ans << endl;

	return 0;
}