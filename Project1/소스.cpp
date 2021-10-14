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
	fastio;
	int N;
	cin >> N;

	vector<int> level;
	for (int i = 0; i < N; i++) {
		int temp; cin >> temp;
		level.push_back(temp);
	}

	int count = 0;
	for (int i = N - 1; i >= 1; i--) {
		if (level[i] <= level[i - 1]) {
			while (1) {
				if (level[i] > level[i - 1])
					break;
				level[i - 1]--;
				count++;
			}
		}
	}

	cout << count << endl;
}