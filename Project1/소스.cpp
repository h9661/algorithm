#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> arr(N, 0);

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int M;
	cin >> M;

	sort(arr.begin(), arr.end());

	int sum = 0;
	int left = 0;
	int right = arr[N - 1];

	while (left <= right) {
		sum = 0;
		int center = (left + right) / 2;

		for (int i = 0; i < N; i++)
			sum += min(center, arr[i]);

		if (sum <= M)
			left = center + 1;
		else
			right = center - 1;
	}

	cout << right << endl;
}