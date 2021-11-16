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

int main() {
	int tc;
	cin >> tc;

	while (tc--) {
		int N;
		cin >> N;
		vector<char> arr(N, NULL);

		for (int i = 0; i < N; i++)
			cin >> arr[i];

		deque<char> ans;

		char temp = NULL;

		for (int i = 0; i < N; i++) {
			if (i == 0) {
				temp = arr[0];
				ans.push_back(arr[0]);
				continue;
			}
			
			if (temp < arr[i])
				ans.push_back(arr[i]);
			else
				ans.push_front(arr[i]);

			temp = ans.front();
		}

		for (auto i : ans)
			cout << i;
		cout << endl;
	}
}