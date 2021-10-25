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
	int N, K, M;
	cin >> N >> K >> M;

	int deleted = 0;
	int count = 1;
	bool flag = false;
	deque<int> dq;

	for (int i = 1; i <= N; i++)
		dq.push_back(i);
	
	while (!dq.empty()) {
		if (count == K) {
			if (flag == false) {
				cout << dq.front() << " ";
				dq.pop_front();
			}
			else {
				cout << dq.back() << " ";
				dq.pop_back();
			}

			count = 1;
			deleted++;
		}
		else {
			if (flag == false) {
				int temp = dq.front();
				dq.push_back(temp);
				dq.pop_front();
				count++;
			}
			else {
				int temp = dq.back();
				dq.push_front(temp);
				dq.pop_back();
				count++;
			}
		}

		if (deleted == M) {
			flag = !flag;
			deleted = 0;
		}
	}

	return 0;
}