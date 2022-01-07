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

int N;
string ans;

bool IsGoodSequence(string str) {
	for (int i = 1; i <= str.size() / 2; i++) {
		for (int idx = 0; idx < str.size() - i; idx++) {
			if (str.substr(idx, i) == str.substr(idx + i, i))
				return false;
		}
	}

	return true;
}

void backtracking(int count) {
	if (count == N) {
		cout << ans << endl;
		exit(0);
	}
	else {
		for (int i = 1; i <= 3; i++) {
			if (IsGoodSequence(ans + to_string(i))) {
				ans += to_string(i);

				backtracking(count + 1);
				
				ans.pop_back();
			}
		}
	}
}

int main() {
	fastio;
	cin >> N;
	backtracking(0);
}