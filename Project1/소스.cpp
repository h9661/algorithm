#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAX_N = 2e5;

int main() {
	int t;
	cin >> t;

	for (int _ = 0; _ < t; _++) {
		int n;
		cin >> n;

		vector<int> a(n);
		map<int, int> cnt;

		for (int i = 0; i < n; i++) {
			cin >> a[i];
			cnt[a[i]]++;
		}

		sort(a.begin(), a.end());

		stack<int> st;
		vector<ll> ans(n + 1, -1);

		ll sum = 0;

		for (int i = 0; i <= n; i++) {
			if (i > 0 && cnt[i - 1] == 0) {
				if (st.empty())
					break;

				int j = st.top();
				st.pop();
				sum += i - j - 1;
			}

			ans[i] = sum + cnt[i];

			while (i > 0 && cnt[i - 1] > 1) {
				cnt[i - 1]--;
				st.push(i - 1);
			}
		}

		for (ll x : ans)
			cout << x << " ";

		cout << endl;
	}
}