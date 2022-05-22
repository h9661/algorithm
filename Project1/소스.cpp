#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int N, M;
		cin >> N >> M;

		deque<int> q;
		for (int i = 0; i < N; i++) {
			int temp;
			cin >> temp;

			q.push_back(temp);
		}

		int ans = 0;
		int idx = M;

		while (1) {
			if (q.front() == *max_element(q.begin(), q.end())) {
				q.pop_front();
				ans++;

				if (idx == 0) {
					cout << ans << endl;
					break;
				}
				else
					idx -= 1;
			}
			else {
				q.push_back(q.front());
				q.pop_front();

				if (idx == 0)
					idx = q.size() - 1;
				else
					idx -= 1;
			}
		}
	}
}