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
	fastio;
	int tc;
	cin >> tc;

	while (tc--) {
		int N;
		cin >> N;

		string start, end;
		cin >> start;
		cin >> end;

		int ans = 0;
		int count_WB = 0;
		int count_BW = 0;

		for (int i = 0; i < start.size(); i++) {
			if (start[i] == 'W' && end[i] == 'B')
				count_WB++;
			if (start[i] == 'B' && end[i] == 'W')
				count_BW++;
		}

		if (count_WB < count_BW) {
			count_BW -= count_WB;
			ans += count_WB;
			ans += count_BW;
		}
		else {
			count_WB -= count_BW;
			ans += count_BW;
			ans += count_WB;
		}

		cout << ans << endl;
	}
}