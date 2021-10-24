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
	int N, M;
	cin >> N >> M;

	vector<int> arr(M, 0);

	for (int i = 0; i < M; i++)
		cin >> arr[i];

	deque<int> dq;
	for (int i = 1; i <= N; i++)
		dq.push_back(i);

	int count = 0;
	int ans = 0;
	while (count < M) {
		int findNumber = arr[count];
		int findNumberIndex = 0;

		for (int i = 0; i < dq.size(); i++) {
			if (dq[i] == findNumber) {
				findNumberIndex = i;
				break;
			}
		}

		while (1) {
			if (dq.front() == findNumber) {
				dq.pop_front();
				count++;
				break;
			}
			else if (findNumberIndex <= (dq.size() / 2)) {
				int temp = dq.front();
				dq.push_back(temp);
				dq.pop_front();
				ans++;
			}
			else {
				int temp = dq.back();
				dq.push_front(temp);
				dq.pop_back();
				ans++;
			}
		}
	}

	cout << ans << endl;
}