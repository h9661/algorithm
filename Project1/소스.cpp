#include <bits/stdc++.h>
#define endl '\n'
#define ll pair<long long, long long>
#define ii pair<int, int>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	vector<ii> arr;
	for (int i = 0; i < N; i++) {
		int w, v;
		cin >> w >> v;

		arr.push_back(make_pair(w, v));
	}

	vector<int> backpack;
	for (int i = 0; i < K; i++) {
		int x;
		cin >> x;

		backpack.push_back(x);
	}

	sort(arr.begin(), arr.end(), [](ii a, ii b) {
		if (a.first != b.first)
			return a.first < b.first;
		else
			return a.second > b.second;
		}
	);
	sort(backpack.begin(), backpack.end(), [](int a, int b){
		return a < b;
		}
	);

	priority_queue<int, vector<int>, less<int>> pq;

	int idx = 0;
	long long ans = 0;

	for (int i = 0; i < K; i++) {
		while (idx < N and backpack[i] >= arr[idx].first)
			pq.push(arr[idx++].second);

		if (!pq.empty()) {
			ans += pq.top();
			pq.pop();
		}
	}

	cout << ans << endl;
}