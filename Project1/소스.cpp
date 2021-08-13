#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define ii pair<int, int>
using namespace std;

int N, M;
vector<int> arr;

int main() {
	cin >> N;
	arr.resize(N + 1);

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.begin() + N);

	cin >> M;

	int ans = 0;

	for (int i = 0; i < N; i++) {
		int left = 0;
		int right = N - 1;

		while (left <= right) {
			int mid = (left + right) / 2;

			if (arr[mid] + arr[i] == M) {
				ans++;
				break;
			}
			else if (arr[mid] + arr[i] < M)
				left = mid + 1;
			else
				right = mid - 1;
		}
	}

	cout << ans / 2 << endl;

	return 0;
}