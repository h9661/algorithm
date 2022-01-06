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

const int MAX = 21;
int N;
int arr[MAX][MAX];
bool check[MAX];
int ans = 2e9;

void backtraking(int count, int idx) {
	if (count == N / 2) {
		vector<int> start;
		vector<int> link;
		for (int i = 1; i <= N; i++) {
			if (check[i] == true)
				start.push_back(i);
			else
				link.push_back(i);
		}
		int start_sum = 0;
		int link_sum = 0;
		for (int i = 0; i < start.size(); i++) {
			for (int j = 0; j < start.size(); j++) {
				start_sum += arr[start[i]][start[j]];
			}
		}

		for (int i = 0; i < link.size(); i++) {
			for (int j = 0; j < link.size(); j++) {
				link_sum += arr[link[i]][link[j]];
			}
		}

		ans = min(ans, abs(start_sum - link_sum));
	}
	else {
		for (int i = idx; i <= N; i++) {
			if (check[i] == false) {
				check[i] = true;

				backtraking(count + 1, i + 1);

				check[i] = false;
			}
		}
	}
}

int main() {
	fastio;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			cin >> arr[i][j];
	}

	backtraking(0, 1);

	cout << ans << endl;
}