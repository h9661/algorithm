#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main() {
	int N;
	cin >> N;

	vector<ll> arr(N, 0);

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	vector<ll> differ(N - 1, 0);

	for (int i = 0; i < N - 1; i++)
		differ[i] = arr[i + 1] - arr[i];

	int k = 987654321;
	for (int i = 0; i < N - 2; i++) {
		int temp = gcd(differ[i], differ[i + 1]);

		if (temp < k)
			k = temp;
	}

	ll count = 0;
	for (int i = arr[0]; i <= arr[N - 1]; i += k)
		count++;

	cout << count - arr.size() << endl;

	return 0;
}