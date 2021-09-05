#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

vector<int> arr;
bool check[300000];
int N, S;
int g_count = 0;

void bfs(int sum, int count) {
	if (sum == S && count > 0) {
		g_count++;
	}

	if (count == N)
		return;

	for (int i = count; i < arr.size(); i++) {
		bfs(arr[i] + sum, i + 1);
	}
}

int main() {
	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;

		arr.push_back(temp);
	}

	bfs(0, 0);

	cout << g_count << endl;
}