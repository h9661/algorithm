#include <bits/stdc++.h>
#pragma warning (disable : 4996)
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

int main() {
	int N, L;
	cin >> N >> L;

	vector<int> arr(N, 0);

	for (int i = 0; i < N; i++)
		cin >> arr[i];
	arr.push_back(987654321);

	sort(arr.begin(), arr.end());

	int i = 0;
	int j;
	int count = 0;
	while (i < N) {
		int temp = arr[i];
		j = i + 1;

		while (j <= N) {
			if (arr[j] - temp <= L - 1) {
				j++;
			}
			else {
				i += j - i;
				count++;
				break;
			}
		}

	}

	cout << count << endl;
}