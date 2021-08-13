#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define ii pair<int, int>
using namespace std;

int main() {
	int N, S;
	cin >> N >> S;

	vector<int> arr(N + 1, 0);

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int left = 0;
	int right = 0;
	int sum = 0;
	int minLength = 1e9;

	while (right <= N) {
		if (sum < S) {
			sum += arr[right++];
		}
		else if (sum >= S) {
			sum -= arr[left++];

			if (minLength > right - left)
				minLength = right - left + 1;
		}
	}

	if (minLength == 1e9)
		cout << "0" << endl;
	else
		cout << minLength << endl;

	return 0;
}