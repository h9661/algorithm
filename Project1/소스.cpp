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

vector<int> arr(9, 0);
vector<int> store;
bool check[9];
bool flag = false;

void bfs(int count, int sum, int idx) {
	if (count == 7 && sum == 100) {
		if (flag)
			return;

		for (int i = 0; i < 7; i++)
			cout << store[i] << " ";
		flag = true;
	}
	else {
		for (int i = idx; i < 9; i++) {
			if (check[i] == false) {
				check[i] = true;

				store.push_back(arr[i]);
				bfs(count + 1, sum + arr[i], i + 1);
				store.pop_back();

				check[i] = false;
			}
		}
	}
}

int main() {
	for (int i = 0; i < 9; i++)
		cin >> arr[i];
	sort(arr.begin(), arr.end());
	bfs(0, 0, 0);
	return 0;
}