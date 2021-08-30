#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

const int MAX = 5000 + 1;
ll arr[MAX];

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr, arr + N);

	int left = 0;
	int right = N - 1;

	ll minimum = 4e9;

	vector<ll> store;
	ll temp1 = arr[0];
	ll temp2 = arr[1];
	ll temp3 = arr[2];

	for (int i = 0; i < N; i++) {
		left = 0;
		right = N - 1;

		while (left < right) {
			ll sum = arr[left] + arr[right] + arr[i];

			if (abs(sum) < minimum) {
				if (i == left || i == right) {
					if (sum < 0)
						left += 1;
					else
						right -= 1;
					continue;
				}

				minimum = abs(sum);
				temp1 = arr[left];
				temp2 = arr[right];
				temp3 = arr[i];
			}

			if (sum < 0)
				left += 1;
			else
				right -= 1;

		}
	}

	store.push_back(temp1);
	store.push_back(temp2);
	store.push_back(temp3);

	sort(store.begin(), store.end());

	for (auto i : store)
		cout << i << " ";

	cout << "hello!!" << endl;

	return 0;
}