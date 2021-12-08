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
vector<int> arr;
vector<bool> check;
vector<int> temp;
int ans = -1;

void backtracking(int count) {
	if (count == N) {
		int sum = 0;
		for (int i = 0; i < N - 1; i++)
			sum += abs(temp[i] - temp[i + 1]);

		ans = max(ans, sum);
	}
	else {
		for (int i = 0; i < N; i++) {
			if (check[i] == false) {
				check[i] = true;

				temp.push_back(arr[i]);
				backtracking(count + 1);
				temp.pop_back();

				check[i] = false;
			}
		}
	}
}

int main() {
	fastio;
	cin >> N;
	arr.resize(N, 0);
	check.resize(N, 0);
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	backtracking(0);
	
	cout << ans << endl;
}