#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define ii pair<int, int>
using namespace std;

int N, M;
vector<int> arr;

int main() {
	cin >> N >> M;
	arr.resize(N + 1);

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int ans = 0;

	int start = 0;
	int end = 0;
	int sum = 0;

	while (end <= N) {
		if (sum >= M)
			sum -= arr[start++];
		else if (sum < M)
			sum += arr[end++];
		if (sum == M)
			ans++;
	}

	cout << ans << endl;

	return 0;
}