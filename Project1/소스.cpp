#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define ii pair<int, int>
using namespace std;

int main() {
	fastio;
	int N;
	cin >> N;

	vector<int> arr(N, 0);

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());

	int left = 0;
	int right = N - 1;

	int min = abs(arr[left] + arr[right]);

	int temp1 = arr[left];
	int temp2 = arr[right];

	while (left < right) {
		int sum = arr[left] + arr[right];

		if (min >= abs(sum)) {
			min = abs(sum);
			temp1 = arr[left];
			temp2 = arr[right];
		}

		if (sum < 0)
			left += 1;
		else
			right -= 1;

	}

	cout << temp1 << " " << temp2 << endl;

	return 0;
}