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

const int MAX = 50;
int arr[MAX][MAX];
int N, M;
vector<pii> homePosArr;
vector<pair<pii, bool>> chPosArr;
int ans = 2e9;

int FindDistance(pii x, pii y) {
	return abs(x.first - y.first) + abs(x.second - y.second);
}

void dfs(int idx, int count) {
	if (count == M) {
		int sum = 0;

		for (int i = 0; i < homePosArr.size(); i++) {
			int minDist = 2e9;

			for (int j = 0; j < chPosArr.size(); j++) {
				if(chPosArr[j].second == true)
					minDist = min(minDist, FindDistance(homePosArr[i], chPosArr[j].first));
			}

			sum += minDist;
		}

		ans = min(sum, ans);

	}
	else {
		for (int i = idx; i < chPosArr.size(); i++) {
			if (chPosArr[i].second == false) {
				chPosArr[i].second = true;

				dfs(i, count + 1);

				chPosArr[i].second = false;
			}
		}
	}
}

int main() {
	fastio;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];

			if (arr[i][j] == 1)
				homePosArr.push_back(make_pair(i, j));
			else if (arr[i][j] == 2)
				chPosArr.push_back({ make_pair(i, j), false });
		}
	}

	dfs(0, 0);

	cout << ans << endl;
}